//We support Email, SMS, Push notifications.
//Design a system to send notifications

#include<iostream>
#include<string>
#include<memory>
#include<vector>
enum class NotificationType { EMAIL, SMS, PUSH };

class INotification {
    public:
      virtual void send(const std::string& message) = 0;
      virtual ~INotification() = default;
};

class EmailNotification : public INotification {
public:
    void send(const std::string& message) override {
        std::cout << "Sending Email: " << message << std::endl;
    }
};

class SMSNotification : public INotification {
public:
    void send(const std::string& message) override {
        std::cout << "Sending SMS: " << message << std::endl;
    }
};

class PushNotification : public INotification {
public:
    void send(const std::string& message) override {
        std::cout << "Sending Push Notification: " << message << std::endl;
    }
};

class NotificationFactory {
    public:
    static std::unique_ptr<INotification> createNotification(NotificationType type) {
          switch (type) {
              case NotificationType::EMAIL:
                  return std::make_unique<EmailNotification>();
              case NotificationType::SMS:
                  return std::make_unique<SMSNotification>();
              case NotificationType::PUSH:
                  return std::make_unique<PushNotification>();
              default:
                  return nullptr;
          }
      }
};

int main() {
    if (const auto notifier = NotificationFactory::createNotification(NotificationType::EMAIL)) {
        notifier->send("Hello new systen email");
    }
    return 0;
}