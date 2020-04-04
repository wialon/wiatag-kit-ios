//
//  PeriodicallyTimer.swift
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/13/20.
//  Copyright © 2020 gria. All rights reserved.
//

import Foundation

extension PeriodicallyTimer {
    enum State {
        case suspended
        case resumed
    }
}

class PeriodicallyTimer: NSObject {
    // MARK: - Properties

    let timeInterval: TimeInterval
    @objc public var completion: (() -> Void)?
    let queue: DispatchQueue?

    private var state: State = .suspended

    private lazy var timer: DispatchSourceTimer = {
        let timer: DispatchSourceTimer = {
            if let queue = self.queue {
                return DispatchSource.makeTimerSource(queue: queue)
            } else {
                return DispatchSource.makeTimerSource()
            }
        }()

        timer.schedule(deadline: .now() + self.timeInterval,
                       repeating: self.timeInterval)
        timer.setEventHandler(handler: { [weak self] in
            self?.completion?()
        })

        return timer
    }()

    // MARK: - Life cycle

    @objc
    public init(timeInterval: TimeInterval,
                queue: DispatchQueue? = nil) {
        self.timeInterval = timeInterval
        self.queue = queue
    }

    deinit {
        timer.setEventHandler {}
        timer.cancel()
        
        resume()
        completion = nil
    }

    // MARK: - Public methods

    @objc public func resume() {
        guard state == .suspended else {
            return
        }

        state = .resumed
        timer.resume()
    }

    @objc public func suspend() {
        guard state == .resumed else {
            return
        }

        state = .suspended
        timer.suspend()
    }
}
