class Transaction{
public:
    Transaction();
    virtual void logTransaction() const = 0;
};

Transaction::Transaction()
{
    logTransaction();
}

class BuyTransaction : public Transaction {
public:
    virtual void logTransaction() const;
};

class SellTransaction: public Transaction{
public:
    virtual void logTransaction() const;
};