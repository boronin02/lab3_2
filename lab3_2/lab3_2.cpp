#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// 1. Класс для представления пользователя
class User {
private:
    int id;                        // ID пользователя
    char name[50];                 // Имя пользователя
    char username[50];             // Логин
    char password[50];             // Пароль
    char accountCreationDate[20];  // Дата создания аккаунта
    double balance;                // Баланс

public:
    User(int userId, const char* userName, const char* userUsername,
        const char* userPassword, const char* creationDate, double userBalance) {
        id = userId;
        strncpy(name, userName, sizeof(name));
        strncpy(username, userUsername, sizeof(username));
        strncpy(password, userPassword, sizeof(password));
        strncpy(accountCreationDate, creationDate, sizeof(accountCreationDate));
        balance = userBalance;
    }

    void displayInfo() const {
        printf("ID пользователя: %d\n", id);
        printf("Имя пользователя: %s\n", name);
        printf("Логин: %s\n", username);
        printf("Дата создания аккаунта: %s\n", accountCreationDate);
        printf("Баланс: %.2f рублей\n\n", balance);
    }

    // Геттер для имени пользователя
    const char* getUsername() const {
        return username;
    }
};

// 2. Класс для представления игры казино
class Game {
private:
    char gameName[50];        // Название игры
    double minBet;            // Минимальная ставка
    double maxBet;            // Максимальная ставка
    double payoutMultiplier;  // Множитель выигрыша

public:
    Game(const char* name, double min, double max, double multiplier) {
        strncpy(gameName, name, sizeof(gameName));
        minBet = min;
        maxBet = max;
        payoutMultiplier = multiplier;
    }

    void displayInfo() const {
        printf("Игра: %s\n", gameName);
        printf("Минимальная ставка: %.2f рублей\n", minBet);
        printf("Максимальная ставка: %.2f рублей\n", maxBet);
        printf("Множитель выигрыша: %.2fx\n\n", payoutMultiplier);
    }

    // Геттер для названия игры
    const char* getGameName() const {
        return gameName;
    }
};

// 3. Класс для представления транзакции
class Transaction {
private:
    int id;                  // ID транзакции
    int userId;              // ID пользователя
    double amount;           // Сумма транзакции
    char timestamp[20];      // Время транзакции

public:
    Transaction(int transId, int usrId, double transAmount, const char* time) {
        id = transId;
        userId = usrId;
        amount = transAmount;
        strncpy(timestamp, time, sizeof(timestamp));
    }

    void displayInfo() const {
        printf("ID транзакции: %d\n", id);
        printf("ID пользователя: %d\n", userId);
        printf("Сумма транзакции: %.2f рублей\n", amount);
        printf("Время транзакции: %s\n\n", timestamp);
    }
};

// 4. Класс для представления игрового раунда
class GameRound {
private:
    User* player;            // Игрок
    Game* game;              // Игра
    double betAmount;        // Сумма ставки
    int result;              // 0 - проигрыш, 1 - выигрыш

public:
    GameRound(User* p, Game* g, double bet, int res) {
        player = p;
        game = g;
        betAmount = bet;
        result = res;
    }

    void displayResult() const {
        printf("Игрок: %s\n", player->getUsername());
        printf("Игра: %s\n", game->getGameName());
        printf("Ставка: %.2f рублей\n", betAmount);
        printf("Результат: %s\n\n", (result ? "Выигрыш" : "Проигрыш"));
    }
};

// 5. Класс для представления джекпота
class Jackpot {
private:
    double currentAmount;    // Текущая сумма джекпота
    int isWon;               // Флаг выигрыша: 1 - джекпот сорван, 0 - нет

public:
    Jackpot(double amount, int won) {
        currentAmount = amount;
        isWon = won;
    }

    void displayInfo() const {
        printf("Текущая сумма джекпота: %.2f рублей\n", currentAmount);
        printf("Состояние джекпота: %s\n\n", (isWon ? "Сорван" : "Не сорван"));
    }
};

// 6. Класс для представления бонусов
class Bonus {
private:
    char bonusType[30];      // Тип бонуса
    double bonusAmount;      // Сумма бонуса
    int isActive;            // Флаг активности бонуса

public:
    Bonus(const char* type, double amount, int active) {
        strncpy(bonusType, type, sizeof(bonusType));
        bonusAmount = amount;
        isActive = active;
    }

    void displayInfo() const {
        printf("Тип бонуса: %s\n", bonusType);
        printf("Сумма бонуса: %.2f рублей\n", bonusAmount);
        printf("Статус бонуса: %s\n\n", (isActive ? "Активен" : "Не активен"));
    }
};

// Основная функция программы
int main() {
    setlocale(LC_ALL, "rus");

    // Пример данных для тестирования
    User* user = new User(1, "Иван Иванов", "ivanov", "password123", "2024-10-01", 100.0);
    Game* game = new Game("Однорукий бандит", 5.0, 100.0, 2.5);
    Transaction* transaction = new Transaction(101, 1, 50.0, "2024-10-18 15:30");
    GameRound* round = new GameRound(user, game, 10.0, 1);
    Jackpot* jackpot = new Jackpot(5000.0, 0);
    Bonus* bonus = new Bonus("Фриспины", 20.0, 1);

    // Динамический массив объектов
    int numberOfUsers = 3;
    User** userArray = new User * [numberOfUsers];
    userArray[0] = new User(2, "Петр Петров", "petrov", "password456", "2024-10-02", 200.0);
    userArray[1] = new User(3, "Сидор Сидоров", "sidorov", "password789", "2024-10-03", 300.0);

    // Отображение данных
    user->displayInfo();
    game->displayInfo();
    transaction->displayInfo();
    round->displayResult();
    jackpot->displayInfo();
    bonus->displayInfo();

    // Отображение пользователей из динамического массива
    for (int i = 0; i < numberOfUsers; ++i) {
        userArray[i]->displayInfo();
    }

    // Освобождение памяти
    delete user;
    delete game;
    delete transaction;
    delete round;
    delete jackpot;
    delete bonus;

    for (int i = 0; i < numberOfUsers; ++i) {
        delete userArray[i];
    }
    delete[] userArray;

    return 0;
}