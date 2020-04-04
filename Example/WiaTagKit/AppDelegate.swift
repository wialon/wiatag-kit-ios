//
//  AppDelegate.swift
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

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, UNUserNotificationCenterDelegate {
    // MARK: - Properties

    var window: UIWindow?

    lazy var messageManager: WTMessageManager = WTMessageManager(host: "193.193.165.165",
                                                                 port: 20963,
                                                                 deviceId: "your device id",
                                                                 password: "your password")

    // MARK: - Implementation UIApplicationDelegate
    func application(_ application: UIApplication,
                     didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey : Any]? = nil) -> Bool {
        messageManager.setLogLevel(.verbose)

        return true
    }
}
