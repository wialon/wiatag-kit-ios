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
    
    //Please init sender with your test data
    let sender = WTMessageSender(host: "193.193.165.165", port: 20963, unitId: "your unit id", password: "your password")

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let message = WTMessage { builder in
            let string = "string"
            if let data = string.data(using: .utf8) {
                builder.addParam("data", withBinaryValue: data)
            }
            builder.addParam("double0", withDoubleValue: NSNumber(value: 18.48))
            builder.addParam("float0", withFloatValue: NSNumber(value: 7.40))
            builder.addParam("int0", withIntValue: NSNumber(value: 12))
            builder.addParam("long0", withLongValue: NSNumber(value: 1432423))
            builder.addParam("text0", withText: "asdasd")
            builder.batteryLevel = 12
            if let image = UIImage(named: "free_image.jpg"), let data = UIImageJPEGRepresentation(image, 1) {
                builder.image = WTImage(imageData: data, named: "image.jpg")
            }
            builder.isSos = true
            builder.location = WTLocation(location: CLLocation(latitude: 34, longitude: 53))
            builder.text = "message"
        }
        sender.send(message) { error in
            guard let error = error else {
                print("no errors")
                return
            }
            print("error is \(error)")
        }
    }
}

