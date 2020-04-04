//
//  DuplicationValidator.swift
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/19/20.
//  Copyright © 2020 gria. All rights reserved.
//

import Foundation
import WiaTagKit

class DuplicationValidator: NSObject, WTDuplicatable {
    // MARK: - Properties

    @objc
    private(set) var items: [WTIdentifiable] = []

    // MARK: - Implementation WTDuplicatable

    @objc public func isDuplicate(withCommand command: WTIdentifiable) -> Bool {
        let isDuplicate = items.contains {
            command.identifier == $0.identifier
        }

        if !isDuplicate {
            items.append(command)
        }

        return isDuplicate
    }
}
