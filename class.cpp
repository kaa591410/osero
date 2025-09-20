#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>
using namespace sf;
using namespace std;
class Han {
    CircleShape black;
    CircleShape white;
    int x=0, y=0, ban[15][15] = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    };
public:
    Han() {
        black.setFillColor(Color::Black);
        white.setFillColor(Color::White);
        black.setRadius(25.f);
        white.setRadius(25.f);
        black.setOrigin(black.getRadius(), black.getRadius());
        white.setOrigin(white.getRadius(), white.getRadius());
        black.setPosition(Vector2f(50.f, 50.f));
        white.setPosition(Vector2f(50.f, 100.f));
    }
    void zah(int a, int b);
    void hyo(RenderWindow& window);
    void banh(int *a,int b);
    int hant(int *);
};
int main()
{
    int a = 1, judge=1,abc=1, x = 1, y = 1;
    Han han;
    RenderWindow window(sf::VideoMode(800, 800), "gomokunarabe");
    Font font;
    if (!font.loadFromFile("MPLUS1p-Regular.ttf")) {
        return -1;
    }
    vector<RectangleShape> tsen;
    for (int i = 1; i < 16; i++) {
        for (int g = 1; g < 15; g++) {
            RectangleShape sen;
            sen.setFillColor(Color::Black);
            sen.setSize(Vector2f(2.f, 50.f));
            sen.setPosition(i * 50, g * 50);
            tsen.push_back(sen);
        }
    }
    for (int i = 1; i < 16; i++) {
        for (int g = 1; g < 15; g++) {
            RectangleShape sen;
            sen.setFillColor(Color::Black);
            sen.setSize(Vector2f(50.f, 2.f));
            sen.setPosition(g * 50, i * 50);
            tsen.push_back(sen);
        }
    }
    vector<RectangleShape> swaku;
    for (int i = 0; i < 16; i++) {
        for (int g = 0; g < 16; g++) {
            if (i == 0|| g==0 || i==15 || g==15) {
                RectangleShape waku;
                waku.setFillColor(Color(200, 170, 130));
                waku.setSize(Vector2f(50.f, 50.f));
                waku.setPosition(i*50, g*50);
                swaku.push_back(waku);
            }
        }
    }
    Vector2u windows = window.getSize();
    RectangleShape hazi;
    hazi.setFillColor(Color::Black);
    hazi.setSize(Vector2f(800.f, 800.f));
    Text text0;
    text0.setFont(font);
    text0.setString(L"黒が先行です");
    text0.setCharacterSize(100);
    FloatRect text01 = text0.getLocalBounds();
    text0.setOrigin(text01.left + text01.width / 2.0f, text01.top + text01.height / 2.0f);
    text0.setPosition(windows.x / 2.0f, windows.y / 3);
    Text tex;
    tex.setFont(font);
    tex.setString(L"キーを押すとはじまります");
    tex.setCharacterSize(40);
    FloatRect tex1 = tex.getLocalBounds();
    tex.setOrigin(tex1.left + tex1.width / 2.0f, tex1.top + tex1.height / 2.0f);
    tex.setPosition(windows.x / 2.0f, windows.y / 2.0f);
    Text text;
    text.setFont(font);
    text.setString(L"黒の勝利です");
    text.setCharacterSize(100);
    text.setFillColor(Color::Red);
    FloatRect textb = text.getLocalBounds();
    text.setOrigin(textb.left + textb.width / 2.0f, textb.top + textb.height / 2.0f);
    text.setPosition(windows.x / 2.0f, windows.y / 2.0f);
    Text text2;
    text2.setFont(font);
    text2.setString(L"白の勝利です");
    text2.setCharacterSize(100);
    text2.setFillColor(Color::Red);
    FloatRect textw = text2.getLocalBounds();
    text2.setOrigin(textw.left + textw.width / 2.0f, textw.top + textw.height / 2.0f);
    text2.setPosition(windows.x / 2.0f, windows.y / 2.0f);
    Text text3;
    text3.setFont(font);
    text3.setString(L"同点です");
    text3.setCharacterSize(100);
    text3.setFillColor(Color::Red);
    FloatRect textbw = text3.getLocalBounds();
    text3.setOrigin(textbw.left + textbw.width / 2.0f, textbw.top + textbw.height / 2.0f);
    text3.setPosition(windows.x / 2.0f, windows.y / 2.0f);
    while (window.isOpen())
    {
        window.clear(Color(210, 180, 140));
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                window.close();
            }
            if (event.type == Event::KeyPressed) {
                abc = 1;
            }
            if (abc != 0) {
                if (event.type == Event::MouseButtonPressed) {
                    Vector2i pt = Mouse::getPosition(window);
                    for (x = 1; x < 16; x++) {
                        if ((pt.x - 25) / (50 * x) == 0 || x == 15) {
                            x = x - 1;
                            break;
                        }
                    }
                    for (y = 1; y < 16; y++) {
                        if ((pt.y - 25) / (50 * y) == 0 || y == 15) {
                            y = y - 1;
                            break;

                        }
                    }
                    han.zah(x, y);
                    han.banh(&a, judge);
                    judge = han.hant(&a);
                    cout << a << endl;
                }
            }                   
        }
        if (abc == 0) {
            window.draw(text0);
            window.draw(tex);
        }
        else if (abc != 0) {
            for (int i = 0; i < swaku.size(); i++) {
                window.draw(swaku[i]);
            }
            for (int i = 0; i < tsen.size(); i++) {
                window.draw(tsen[i]);
            }
            han.hyo(window);
            if (judge == 0) {
                window.draw(text);
            }
            else if (judge == 300) {
                window.draw(text2);
            }
            else if (a == 256) {
                window.draw(text3);
            }            
        }
        window.display();
    }
    return 0;
}

void Han::zah(int a, int b) {
    x = a;
    y = b;
}
void Han::hyo(RenderWindow& window) {
    float blx = 0, bly = 0, whx = 0, why = 0;
    for (int i = 0; i < 15; i++) {
        for (int g = 0; g < 15; g++) {
            if (ban[i][g] == 1) {
                blx = static_cast<float>(50 * (g + 1));
                bly = static_cast<float>(50 * (i + 1));
                black.setPosition(blx, bly);
                window.draw(black);
            }
            else if (ban[i][g] == 2) {
                whx = static_cast<float>(50 * (g + 1));
                why = static_cast<float>(50 * (i + 1));
                white.setPosition(whx, why);
                window.draw(white);
            }
        }
    }  
}
void Han::banh(int *a, int b) {
    if (*a <= 256 && b != 0 &&  b != 300) {
        if (ban[y][x] == 0) {
            if (*a % 2 == 1) {
                ban[y][x] = 1;
            }
            else if (*a % 2 == 0) {
                ban[y][x] = 2;
            }
            *a += 1;
        }
    }
    
}
int Han::hant(int* a) {
    int b = 0;
    for (int i = 0; i < 15; i++) {
        for (int g = 0; g < 15; g++) {
            if (ban[g][i] == 1) {
                b = b + 1;
                if (b == 5)
                    return 0;
            }
            else if (ban[g][i] != 1 || g == 0) {
                b = 0;
            }
        }
        for (int g = 0; g < 15; g++) {
            if (ban[i][g] == 1) {
                b = b + 1;
                if (b == 5)
                    return 0;
            }
            else if (ban[i][g] != 1 || g == 0) {
                b = 0;
            }
        }
    }
    for (int i = 0; i < 11; i++) {
        for (int g = 0; g < 11; g++) {
            if (ban[g][i] == 1) {
                for (int h = 0; h < 5; h++) {
                    if (ban[g + h][i + h] == 1){
                        b = b + 1;
                    if (b == 5)
                        return 0;
                    }
                    else if (ban[g+h][i+h] != 1) {
                        b = 0;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 14; i > 5; i--) {
        for (int g = 0; g < 11;g++) {
            if (ban[i][g] == 1) {
                for (int h = 0; h < 5; h++) {
                    if (ban[i - h][g + h] == 1) {
                        b = b + 1;
                        if (b == 5)
                            return 0;
                    }
                    else if (ban[i - h][g + h] != 1) {
                        b = 0;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 15; i++) {
        for (int g = 0; g < 15; g++) {
            if (ban[g][i] == 2) {
                b = b + 1;
                if (b == 5)
                    return 300;
            }
            else if (ban[g][i] != 2 || g == 0) {
                b = 0;
            }
        }
        for (int g = 0; g < 15; g++) {
            if (ban[i][g] == 2) {
                b = b + 1;
                if (b == 5)
                    return 300;
            }
            else if (ban[i][g] != 2 || g == 0) {
                b = 0;
            }
        }
    }
    for (int i = 0; i < 11; i++) {
        for (int g = 0; g < 11; g++) {
            if (ban[g][i] == 2) {
                for (int h = 0; h < 5; h++) {
                    if (ban[g + h][i + h] == 2) {
                        b = b + 1;
                        if (b == 5)
                            return 300;
                    }
                    else if (ban[g + h][i + h] != 2) {
                        b = 0;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 14; i > 5; i--) {
        for (int g = 0; g < 11; g++) {
            if (ban[i][g] == 2) {
                for (int h = 0; h < 5; h++) {
                    if (ban[i - h][g + h] == 2) {
                        b = b + 1;
                        if (b == 5)
                            return 300;
                    }
                    else if (ban[i - h][g + h] != 2) {
                        b = 0;
                        break;
                    }
                }
            }
        }
    }
}