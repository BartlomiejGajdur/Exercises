class Coordinates{
    public:
        Coordinates(int positionX, int positionY) : 
                                                    positionX_(positionX), 
                                                    positionY_(positionY) {}

    bool operator==(const Coordinates &other)
    {
        return this->positionX_ == other.positionX_ &&
                this->positionY_ == other.positionY_;
    }
    private:
        int positionX_;
        int positionY_;

};