#include <exception> 
#include <string> 
class DeliveryError : public std::exception {
public:
    explicit DeliveryError(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
protected:
    std::string message;
};

// 1. Ошибка при создании заказа
class OrderCreationError : public DeliveryError {
public:
    OrderCreationError() : DeliveryError("Ошибка при создании заказа.") {}
};

// 2. Название не может начинаться с небуквы
class InvalidNameError : public DeliveryError {
public:
    InvalidNameError() : DeliveryError("Заказ не найден.") {}
};

// 3. Пользователь ЗАБАНЕН
class BannedUserError : public DeliveryError {
public:
    BannedUserError() : DeliveryError("Пользователь забанен.") {}
};

// 4. Курьер не найден
class CourierNotFoundError : public DeliveryError {
public:
    CourierNotFoundError() : DeliveryError("Курьер не найден.") {}
};

// 5. Курьер уже занят
class CourierBusyError : public DeliveryError {
public:
    CourierBusyError() : DeliveryError("Курьер уже занят другим заказом.") {}
};

// 6. Недопустимое блюдо
class InvalidEatableError : public DeliveryError {
public:
    InvalidEatableError() : DeliveryError("Недопустимое блюдо.") {}
};

// 7. Ошибка оплаты
class PaymentProcessingError : public DeliveryError {
public:
    PaymentProcessingError() : DeliveryError("Ошибка при обработке оплаты.") {}
};

// 8. Недостаточно средств
class InsufficientFundsError : public DeliveryError {
public:
    InsufficientFundsError() : DeliveryError("Недостаточно средств для оплаты заказа.") {}
};

// 9. "Работник не найден"
class WorkerNotFoundError : public DeliveryError {
public:
    WorkerNotFoundError() : DeliveryError("Превышено время ожидания выполнения операции.") {}
};

// 10. Неправильный процент
class InvalidPercentError : public DeliveryError {
public:
    InvalidPercentError() : DeliveryError("Некорректный процент.") {}
};

// 11. Отрицательное количество продуктов
class NegativeAmountError : public DeliveryError {
public:
    NegativeAmountError() : DeliveryError("Количество не может быть отрицательным.") {}
};

// 12. Не найдена позиция
class PositionNotFoundError : public DeliveryError {
public:
    PositionNotFoundError() : DeliveryError("Нарушение бизнес-правил доставки.") {}
};
