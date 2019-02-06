#include <vector>
using namespace std;

class Tile {
public:
    int number;

    Tile();
    bool hasMine();
    bool hasFlagPlaced();
    bool GetBeenClicked();
    void SetHasMine(bool mine);
    void SetFlag(bool flag);
    void SetBeenClicked(bool clicked);
    void setNeighbors(vector<Tile *> tilesRound);
    vector<Tile *> GetTilesAround();
    int GetNumberOfMinesAround();
    void SetHasNumber(bool number);
    bool GetHasNumber();
    bool SetRevealed(bool rev);
    bool isRevealed();

private:
    bool isNumber;
    bool isMine;
    bool beenClicked;
    bool flag;
    bool revealed;
    std::vector<Tile *> neighbors;
};
