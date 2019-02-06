#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include <iostream>
#include <string>
#include "Board.h"

using namespace sf;
using namespace std;

int Start(RenderWindow &window, Board &gameBoard);


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper");
    int choice = 0;
    while (choice != 3) {
        switch (choice) {
            case 0: {
                Board gameBoard(25, 16);
                choice = Start(window, gameBoard);
                break;
            }
            case 1: {
                Board testOne(25, 16, 1);
                choice = Start(window, testOne);
                break;
            }
            case 2: {
                Board testOne(25, 16, 2);
                choice = Start(window, testOne);
                break;
            }
        }
    }

    return 0;
}

int Start(RenderWindow &window, Board &gameBoard) {
    vector<Sprite> numberSprites;

    Texture num1;
    num1.loadFromFile("images/number_1.png");
    Sprite number1(num1);

    Texture num2;
    num2.loadFromFile("images/number_2.png");
    Sprite number2(num2);

    Texture num3;
    num3.loadFromFile("images/number_3.png");
    Sprite number3(num3);

    Texture num4;
    num4.loadFromFile("images/number_4.png");
    Sprite number4(num4);

    Texture num5;
    num5.loadFromFile("images/number_5.png");
    Sprite number5(num5);

    Texture num6;
    num6.loadFromFile("images/number_6.png");
    Sprite number6(num6);

    Texture num7;
    num7.loadFromFile("images/number_7.png");
    Sprite number7(num7);

    Texture num8;
    num8.loadFromFile("images/number_8.png");
    Sprite number8(num8);

    Texture tile_hidden;
    tile_hidden.loadFromFile("images/tile_hidden.png");
    Sprite tileHidden(tile_hidden);

    Texture tile_revealed;
    tile_revealed.loadFromFile("images/tile_revealed.png");
    Sprite tileRevealed(tile_revealed);

    Texture flagSprite;
    flagSprite.loadFromFile("images/flag.png");
    Sprite flag(flagSprite);

    Texture mineSprite;
    mineSprite.loadFromFile("images/mine.png");    //12 is mine
    Sprite mine(mineSprite);

    Texture happyFace;
    happyFace.loadFromFile("images/face_happy.png");
    Sprite happy(happyFace);

    Texture testoneSprite;
    testoneSprite.loadFromFile("images/test_1.png");
    Sprite testOne(testoneSprite);

    Texture testTwoSprite;
    testTwoSprite.loadFromFile("images/test_2.png");
    Sprite testTwo(testTwoSprite);

    Texture debugSprite;
    debugSprite.loadFromFile("images/debug.png");
    Sprite debug(debugSprite);

    Texture digitsSprite;
    digitsSprite.loadFromFile("images/digits.png");
    Sprite digits(digitsSprite);

    Texture loserFaceSprite;
    loserFaceSprite.loadFromFile("images/face_lose.png");
    Sprite sad(loserFaceSprite);

    Texture winnerFaceSprite;
    winnerFaceSprite.loadFromFile("images/face_win.png");
    Sprite faceWin(winnerFaceSprite);

    numberSprites.push_back(number1);
    numberSprites.push_back(number2);
    numberSprites.push_back(number3);
    numberSprites.push_back(number4);
    numberSprites.push_back(number5);
    numberSprites.push_back(number6);
    numberSprites.push_back(number7);
    numberSprites.push_back(number8);

    int winpixWidth = 32;
    bool showMinesBool = false;
    while (window.isOpen()) {
        Vector2i pos = Mouse::getPosition(window);
        int x = pos.x / winpixWidth;
        int y = pos.y / winpixWidth;

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return 3;
            }

            if (event.type == Event::MouseButtonPressed) {
                if (gameBoard.ClickedOnATile(pos.x, pos.y) && !gameBoard.gameIsOver()) {
                    if (event.key.code == Mouse::Left) {
                        gameBoard.HandleLeftClick(x, y);
                    } else if (event.key.code == Mouse::Right) {
                        gameBoard.HandleRightClick(x, y);
                    }
                } else if (gameBoard.ClickedOnDebug(pos.x, pos.y)) {
                    if (event.key.code == Mouse::Left) {
                        if (!showMinesBool) {
                            showMinesBool = true;
                        } else {
                            showMinesBool = false;
                        }
                    }
                } else if (gameBoard.ClickedOnTestOne(pos.x, pos.y)) {
                    return 1;
                } else if (gameBoard.ClickedOnTestTwo(pos.x, pos.y)) {
                    return 2;
                } else if (gameBoard.ClickedOnFace(pos.x, pos.y)) {
                    return 0;
                }
            }
        }

        window.clear(Color::White);

        vector<vector<Tile>> tileVector = gameBoard.GetBoard();
        for (int i = 0; i <= 24; i++) {
            for (int j = 0; j <= 15; j++) {
                Tile &tile = tileVector[i][j];
                if (!gameBoard.gameIsOver()) {
                    tileHidden.setPosition(i * winpixWidth, j * winpixWidth);
                    window.draw(tileHidden);
                    if (tileVector[i][j].isRevealed()) {
                        tileRevealed.setPosition(i * winpixWidth, j * winpixWidth);
                        window.draw(tileRevealed);
                        if (tile.number > 0) {
                            numberSprites[tile.number - 1].setPosition(i * winpixWidth, j * winpixWidth);
                            window.draw(numberSprites[tile.number - 1]);
                        }
                    }
                    if (tileVector[i][j].hasFlagPlaced()) {
                        flag.setPosition(i * winpixWidth, j * winpixWidth);
                        window.draw(flag);
                    }
                    if (showMinesBool) {
                        if (tileVector[i][j].hasMine()) {
                            mine.setPosition(i * winpixWidth, j * winpixWidth);
                            window.draw(mine);
                        }
                    }

                } else {
                    tileHidden.setPosition(i * winpixWidth, j * winpixWidth);
                    window.draw(tileHidden);
                    if (tileVector[i][j].isRevealed()) {
                        tileRevealed.setPosition(i * winpixWidth, j * winpixWidth);
                        window.draw(tileRevealed);
                        if (tile.number > 0) {
                            numberSprites[tile.number - 1].setPosition(i * winpixWidth, j * winpixWidth);
                            window.draw(numberSprites[tile.number - 1]);
                        }
                    }
                    if (tileVector[i][j].hasFlagPlaced()) {
                        flag.setPosition(i * winpixWidth, j * winpixWidth);
                        window.draw(flag);
                    } else if (tileVector[i][j].hasMine()) {
                        mine.setPosition(i * winpixWidth, j * winpixWidth);
                        window.draw(mine);
                    }
                }
            }
        }

        testOne.setPosition(18 * winpixWidth, 16 * winpixWidth);
        window.draw(testOne);
        testTwo.setPosition(20 * winpixWidth, 16 * winpixWidth);
        window.draw(testTwo);
        debug.setPosition(16 * winpixWidth, 16 * winpixWidth);
        window.draw(debug);
        if (!gameBoard.gameIsOver()) {
            happy.setPosition(10 * winpixWidth, 16 * winpixWidth);
            window.draw(happy);
        } else {
            if (gameBoard.gameIsWon()) {
                faceWin.setPosition(10 * winpixWidth, 16 * winpixWidth);
                window.draw(faceWin);
            } else {
                sad.setPosition(10 * winpixWidth, 16 * winpixWidth);
                window.draw(sad);
            }
        }

        // creates the first 0 permanently in the counter
        digits.setTextureRect(IntRect(0, 0, 21, 32));
        digits.setPosition(0, 16 * winpixWidth);
        window.draw(digits);

        int Width = 21;
        int flagCount = gameBoard.GetFlagCount();
        // shows the appropriate number in the 2nd figure of the counter
        if (flagCount > 0) {
            if (flagCount / 10 == 5) {
                digits.setTextureRect(IntRect(5 * Width, 0, 21, 32));
                digits.setPosition(Width, 16 * winpixWidth);
                window.draw(digits);
            }
            if (flagCount / 10 == 4) {
                digits.setTextureRect(IntRect(4 * Width, 0, 21, 32));
                digits.setPosition(Width, 16 * winpixWidth);
                window.draw(digits);
            }
            if (flagCount / 10 == 3) {
                digits.setTextureRect(IntRect(3 * Width, 0, 21, 32));
                digits.setPosition(Width, 16 * winpixWidth);
                window.draw(digits);
            }
            if (flagCount / 10 == 2) {
                digits.setTextureRect(IntRect(2 * Width, 0, 21, 32));
                digits.setPosition(Width, 16 * winpixWidth);
                window.draw(digits);
            }
            if (flagCount / 10 == 1) {
                digits.setTextureRect(IntRect(Width, 0, 21, 32));
                digits.setPosition(Width, 16 * winpixWidth);
                window.draw(digits);
            }
            if (flagCount / 10 == 0) {
                digits.setTextureRect(IntRect(0, 0, 21, 32));
                digits.setPosition(Width, 16 * winpixWidth);
                window.draw(digits);
            }

            // shows the appropriate 3rd figure in the counter
            if (flagCount % 10 == 9) {
                digits.setTextureRect(IntRect(9 * Width, 0, 21, 32));
                digits.setPosition(2 * Width, 16 * winpixWidth);
                window.draw(digits);
            }
            if (flagCount % 10 == 8) {
                digits.setTextureRect(IntRect(8 * Width, 0, 21, 32));
                digits.setPosition(2 * Width, 16 * winpixWidth);
                window.draw(digits);
            }
            if (flagCount % 10 == 7) {
                digits.setTextureRect(IntRect(7 * Width, 0, 21, 32));
                digits.setPosition(2 * Width, 16 * winpixWidth);
                window.draw(digits);
            }
            if (flagCount % 10 == 6) {
                digits.setTextureRect(IntRect(6 * Width, 0, 21, 32));
                digits.setPosition(2 * Width, 16 * winpixWidth);
                window.draw(digits);
            }
            if (flagCount % 10 == 5) {
                digits.setTextureRect(IntRect(5 * Width, 0, 21, 32));
                digits.setPosition(2 * Width, 16 * winpixWidth);
                window.draw(digits);
            }
            if (flagCount % 10 == 4) {
                digits.setTextureRect(IntRect(4 * Width, 0, 21, 32));
                digits.setPosition(2 * Width, 16 * winpixWidth);
                window.draw(digits);
            }
            if (flagCount % 10 == 3) {
                digits.setTextureRect(IntRect(3 * Width, 0, 21, 32));
                digits.setPosition(2 * Width, 16 * winpixWidth);
                window.draw(digits);
            }
            if (flagCount % 10 == 2) {
                digits.setTextureRect(IntRect(2 * Width, 0, 21, 32));
                digits.setPosition(2 * Width, 16 * winpixWidth);
                window.draw(digits);
            }
            if (flagCount % 10 == 1) {
                digits.setTextureRect(IntRect(Width, 0, 21, 32));
                digits.setPosition(2 * Width, 16 * winpixWidth);
                window.draw(digits);
            }
            if (flagCount % 10 == 0) {
                digits.setTextureRect(IntRect(0, 0, 21, 32));
                digits.setPosition(2 * Width, 16 * winpixWidth);
                window.draw(digits);
            }
        } else {
            // sets the counter to 3 zeroes when it runs out
            digits.setTextureRect(IntRect(0, 0, 21, 32));
            digits.setPosition(Width, 16 * winpixWidth);
            window.draw(digits);
            digits.setTextureRect(IntRect(0, 0, 21, 32));
            digits.setPosition(2 * Width, 16 * winpixWidth);
            window.draw(digits);
        }

        window.display();
    }
    return 0;
}
