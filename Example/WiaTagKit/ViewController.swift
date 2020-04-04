//
//  ViewController.swift
//  WiaTagKit
//
/*
 WiaTagKit (c) by Gurtam
 
 WiaTagKit is licensed under a
 Creative Commons Attribution-NoDerivatives 4.0 International License.
 
 You should have received a copy of the license along with this
 work. If not, see <http://creativecommons.org/licenses/by-nd/4.0/>.
 */

import UIKit
import WiaTagKit

class ViewController: UIViewController {
    // MARK: - Properties

    @IBOutlet private weak var tableView: UITableView!
    @IBOutlet private weak var sendButton: UIButton!
    @IBOutlet private weak var textField: UITextField!
    @IBOutlet private weak var bottomConstraint: NSLayoutConstraint!

    private var messageManager: WTMessageManager?
    private lazy var periodicallyTimer: PeriodicallyTimer = PeriodicallyTimer(timeInterval: 10,
                                                                              queue: nil)
    private lazy var duplicationValidator: DuplicationValidator = DuplicationValidator()

    // MARK: - Life cycle

    override func viewDidLoad() {
        super.viewDidLoad()

        setupTableView()
        setupMessageManager()
        setupTimer()
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)

        NotificationCenter.default.addObserver(self,
                                               selector: #selector(keyboardDidChangeFrame(_:)),
                                               name: UIResponder.keyboardDidChangeFrameNotification,
                                               object: nil)
    }

    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)

        NotificationCenter.default.removeObserver(self)
    }

    // MARK: - Private methods

    func setupTableView() {
        tableView.rowHeight = UITableView.automaticDimension
        tableView.estimatedRowHeight = 100
        tableView.dataSource = self
    }

    func setupMessageManager() {
        let appDelegate = UIApplication.shared.delegate as? AppDelegate

        messageManager = appDelegate?.messageManager
        messageManager?.enableAllServices(completion: nil)
        messageManager?.duplicationValidator = duplicationValidator

        messageManager?.addListener(completion: { [weak self] command in
            DispatchQueue.main.async(execute: {
                self?.tableView.reloadData()
            })
        })
    }

    func setupTimer() {
        periodicallyTimer.completion = { [weak self] in
            self?.messageManager?.checkUpdates()
        }

        periodicallyTimer.resume()
    }

    // MARK: - Keyboard handler

    @objc func keyboardDidChangeFrame(_ notification: Notification?) {
        let userInfo = notification?.userInfo
        let keyboardSize = (userInfo?[UIResponder.keyboardFrameEndUserInfoKey] as AnyObject).cgRectValue.size

        UIView.animate(withDuration: 0.33, animations: {
            self.bottomConstraint.constant = -(keyboardSize.height)
        })
    }

    // MARK: - Actions

    @IBAction func sendButtonPressed(_ sender: UIButton) {
        let msg = WTMessage(block: { [weak self] builder in
            builder.time = Date()
            builder.text = self?.textField.text
        })

        messageManager?.send(msg) { [weak self] error in
            DispatchQueue.main.async(execute: {
                self?.textField.text = nil
                self?.tableView.reloadData()
            })
        }
    }
}

// MARK: - Implementation UITableViewDataSource

extension ViewController: UITableViewDataSource {
    func tableView(_ tableView: UITableView,
                   numberOfRowsInSection section: Int) -> Int {
        return duplicationValidator.items.count
    }

    func tableView(_ tableView: UITableView,
                   cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = UITableViewCell(style: .default,
                                   reuseIdentifier: "TableViewCellIdentifier")

        let item = duplicationValidator.items[indexPath.row] as? NSObject

        cell.textLabel?.numberOfLines = 0
        cell.textLabel?.text = item?.description

        return cell
    }
}
