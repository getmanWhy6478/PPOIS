#pragma once
#include <exception> 
#include <string> 
class DeliveryError : public std::exception {
public:
    explicit DeliveryError(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
protected:
    std::string message;
};

// 1. Ошибка при создании номера
class InvalidNumberError : public DeliveryError {
public:
    InvalidNumberError() : DeliveryError("Некорректный номер телефона.") {}
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

// 4. Повар занят
class CookBusyError : public DeliveryError {
public:
    CookBusyError() : DeliveryError("Повар занят.") {}
};

//5. Бонус кончился или не существует
class BonusExpired : public DeliveryError {
public:
    BonusExpired() : DeliveryError("Срок действия бонуса истёк или бонус не найден ") {}
};

// 6. Недопустимое блюдо
class InvalidEatableError : public DeliveryError {
public:
    InvalidEatableError() : DeliveryError("Недопустимое блюдо.") {}
};

// 7. Человек нигде не работает
class UnempolymentError : public DeliveryError {
public:
    UnempolymentError() : DeliveryError("Работник никуда не назначен.") {}
};

// 8. Недостаточно средств
class InsufficientFundsError : public DeliveryError {
public:
    InsufficientFundsError() : DeliveryError("Недостаточно средств для оплаты заказа.") {}
};

// 9. блюдо не найден"
class EatableNotFoundError : public DeliveryError {
public:
    EatableNotFoundError() : DeliveryError("Блюдо не найдено.") {}
};

// 10. Неправильное время
class NegativeTimeError: public DeliveryError {
public:
    NegativeTimeError () : DeliveryError("Доставка не может занимать отрицательное время.") {}
};

// 11. Отрицательное количество продуктов
class NegativeAmountError : public DeliveryError {
public:
    NegativeAmountError() : DeliveryError("Количество не может быть отрицательным.") {}
};

class LoyaltyProgramError : public DeliveryError {
public:
    LoyaltyProgramError() : DeliveryError("Программа лояльности вам недоступна.") {}
};