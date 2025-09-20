#include <SFML/Graphics.hpp>
#include<iostream>
#include<random>
#include<chrono>
#include<array>
#include<vector>
using namespace std;
using namespace sf;
void column(int ba[8][8], int x,int y, int *order, int *e) {
    int a=0;
    if (*order%2==1){
        for (int i = x + 2; i < 8; i++) {
            if (ba[i-1][y] !=2)
                break;
            else if (ba[i][y] == 1) {
                for (int g = x + 1; g < i; g++) {
                    ba[g][y] = 1;
                    a = 1;
                }
            }
            if (a == 1)
                break;
            
        }
        for (int i = x - 2; i >= 0; i--) {
            if (ba[i + 1][y] !=2)
                break;
            else if (ba[i][y] == 1) {
                for (int g = x - 1; g > i; g--) {
                    ba[g][y] = 1;
                    a = 1;
                }
            }
            if (a == 1)
                break;
        }
    }
    else if (*order % 2 == 0) {
            for (int i = x + 2; i < 8; i++) {
                if (ba[i- 1][y] != 1)
                    break;
                else if (ba[i][y] == 2) {
                    for (int g = x + 1; g < i; g++) {
                        ba[g][y] = 2;
                        a = 1;
                    }
                }
                if (a == 1) {
                    break;
                }
            }
            for (int i = x - 2; i >= 0; i--) {
                if (ba[i+ 1][y] != 1 )
                    break;
                if (ba[i][y] == 2) {
                    for (int g = x - 1; g > i; g--) {
                        ba[g][y] = 2;
                        a = 1;
                    }
                }
                if (a == 1) {
                    break;
                }
            }
    }
    if (a == 1)
        *e = 1;
}

void row(int ba[8][8], int x, int y, int *order, int *e) {
    int a = 0;
    if (*order % 2 == 1) {

        for (int i = y + 2; i < 8; i++) {
            if (ba[x][i- 1] != 2)
                    break;
            if (ba[x][i] == 1) {
                for (int g = y + 1; g < i; g++) {
                    ba[x][g] = 1;
                    a = 1;
                }
            }
            if (a == 1)
                break;
        }
        for (int i = y - 2; i >= 0; i--) {
            if (ba[x][i+1] != 2)                
                    break;
            if (ba[x][i] == 1) {
                for (int g = y - 1; g > i; g--) {
                    ba[x][g] = 1;
                    a = 1;
                }
            }
            if (a == 1)
                break;
        }
    }
    else if (*order % 2 == 0) {
        for (int i = y +2; i < 8; i++) {
            if (ba[x][i-1] !=1 )
                    break;
            if (ba[x][i] == 2) {
                for (int g = y + 1; g < i; g++) {
                    ba[x][g] = 2;
                    a = 1;
                }
            }
            if (a == 1) {
                break;
            }
        }
        for (int i = y - 2; i >= 0; i--) {
            if (ba[x][i+1] !=1 )
                    break;
            if (ba[x][i] == 2) {
                for (int g = y - 1; g > i; g--) {
                    ba[x][g] = 2;
                    a = 1;
                }
            }
            if (a == 1) {
                break;
            }
        }
    }
    if (a == 1)
        *e = 1;
}
void cross(int ba[8][8], int x, int y, int *order, int *e) {
    int a = 0;
    if (*order % 2 == 1) {
        for (int i =2; i < 8; i++) {
            if (x>=6 || y>=6 || ba[x + i-1][y + i-1] != 2) 
                break;
            else if (ba[x + i][y + i] == 1) {
                for (int g = 1; g < i; g++) {
                    ba[x + g][y + g] = 1;
                    a = 1;
                }
            }
            if (x + i >= 7 || y + i >= 7 || a==1)
                break;
        }
        for (int i = 2; i < 8; i++) {
            if (x<=1 || y <= 1 || ba[x - i + 1][y - i + 1] != 2)
                break;
            else if (ba[x - i][y - i] == 1) {
                for (int g = 1; g < i; g++) {
                    ba[x - g][y - g] = 1;
                    a = 1;
                }
            }
            if (x - i <= 0 || y - i <= 0 || a==1)
                break;
        }
        for (int i = 2; i < 8; i++) {
            if (x>=6 || y<=1 || ba[x + i - 1][y - i + 1] != 2)
                break;
            else if (ba[x + i][y - i] == 1) {
                for (int g = 1; g < i; g++) {
                    ba[x + g][y - g] = 1;
                    a = 1;
                }
            }
            if (x + i >= 7 || y - i <= 0 || a==1)
                break;
        }
        for (int i = 2; i < 8; i++) {
            if (x<=1 || y >=6 || ba[x - i + 1][y + i - 1] != 2)
                break;
            else if (ba[x - i][y + i] == 1) {
                for (int g = 1; g < i; g++) {
                    ba[x - g][y + g] = 1;
                    a = 1;
                }
            }
            if (x - i <= 0 || y + i >= 7 || a==1)
                break;
        }
    }
    else if (*order % 2 == 0) {
        for (int i = 2; i < 8; i++) {
            if (x>=6 || y >=6 || ba[x + i - 1][y + i - 1] != 1)
                break;
            else if (ba[x + i][y + i] == 2) {
                for (int g = 1; g < i; g++) {
                    ba[x + g][y + g] = 2;
                    a = 1;
                }
            }
            if (x + i >= 7 || y + i >= 7 || a==1)
                break;
        }
        for (int i = 2; i < 8; i++) {
            if (x<=1 || y<=1 || ba[x - i + 1][y - i + 1] != 1)
                break;
            else if (ba[x - i][y - i] == 2) {
                for (int g = 1; g < i; g++) {
                    ba[x - g][y - g] = 2;
                    a = 1;
                }
            }
            if (x - i <= 0 || y - i <= 0 || a == 1)
                break;
        }
        for (int i = 2; i < 8; i++) {
            if (x>=6 || y<=1 || ba[x + i - 1][y - i + 1] != 1)
                break;
            else if (ba[x + i][y - i] == 2) {
                for (int g = 1; g < i; g++) {
                    ba[x + g][y - g] = 2;
                    a = 1;
                }
            }
            if (x + i >= 7 || y - i <= 0 || a == 1)
                break;
        }
        for (int i = 2; i < 8; i++) {
            if (x<=1 || y>=6 || ba[x - i + 1][y + i - 1] != 1)
                break;
            else if (ba[x - i][y + i] == 2) {
                for (int g = 1; g < i; g++) {
                    ba[x - g][y + g] = 2;
                    a = 1;
                }
            }
            if (x - i <= 0 || y + i >= 7 || a == 1)
                break;
        }
    }
    if (a == 1)
        *e = 1;   
}
int han(int ba[8][8], int *order) {
int fr=0;
for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 6; x++) {
        if (ba[x][y] == 0 && ba[x + 1][y] == 2) {
            for (int i = x + 2; i < 8; i++) {
                if (ba[i][y] == 0)
                    break;
                else if (ba[i][y] == 1) {
                    fr = 1;
                    break;
                }
            }
        }
        if (ba[y][x] == 0 && ba[y][x + 1] == 2) {
            for (int i = x + 2; i < 8; i++) {
                if (ba[y][i] == 0)
                    break;
                else if (ba[y][i] == 1) {
                    fr = 1;
                    break;
                }
            }
        }
        if (fr == 1)
            break;
    }
    for (int x = 7; x >= 2; x--) {
        if (ba[x][y] == 0 && ba[x - 1][y] == 2) {
            for (int i = x - 2; i >= 0; i--) {
                if (ba[i][y] == 0)
                    break;
                else if (ba[i][y] == 1) {
                    fr = 1;
                    break;
                }
            }
        }
        if (ba[y][x] == 0 && ba[y][x - 1] == 2) {
            for (int i = x - 2; i >= 0; i--) {
                if (ba[y][i] == 0)
                    break;
                else if (ba[y][i] == 1) {
                    fr = 1;
                    break;
                }
            }
        }
        if (fr == 1)
            break;
    }

}
for (int x = 0; x < 6; x++) {
    for (int y = 0; y < 6; y++) {
        if (ba[x][y] == 0 && ba[x + 1][y + 1] == 2) {
            for (int i = 2; i < 8; i++) {
                if (x + i > 8 || y + i > 8 || ba[x + i][y + i] == 0)
                    break;
                else if (ba[x + i][y + i] == 1) {
                    fr = 1;
                    break;
                }
            }
        }
    }
    for (int y = 7; y >= 2; y--) {
        if (ba[x][y] == 0 && ba[x + 1][y - 1] == 2) {
            for (int i = 2; i < 8; i++) {
                if (x + i > 8 || y - i <= 0 || ba[x + i][y - i] == 0)
                    break;
                else if (ba[x + i][y - i] == 1) {
                    fr = 1;
                    break;
                }
            }
        }

    }
    if (fr == 1)
        break;
}
for (int x = 7; x >= 2; x--) {
    for (int y = 0; y < 6; y++) {
        if (ba[x][y] == 0 && ba[x - 1][y + 1] == 2) {
            for (int i = 2; i < 8; i++) {
                if (x - i <= 0 || y + i > 8 || ba[x - i][y + i] == 0)
                    break;
                else if (ba[x - i][y + i] == 1) {
                    fr = 1;
                    break;
                }
            }
        }
    }
    for (int y = 7; y >= 2; y--) {
        if (ba[x][y] == 0 && ba[x - 1][y - 1] == 2) {
            for (int i = 2; i < 8; i++) {
                if (x - i <= 0 || y - i <= 0 || ba[x - i][y - i] == 0)
                    break;
                else if (ba[x - i][y - i] == 1) {
                    fr = 1;
                    break;
                }
            }
        }

    }
    if (fr == 1)
        break;
}
for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 6; x++) {
        if (ba[x][y] == 0 && ba[x + 1][y] == 1) {
            for (int i = x + 2; i < 8; i++) {
                if (ba[i][y] == 0)
                    break;
                else if (ba[i][y] == 2) {
                    if (fr == 1)
                        fr = 3;
                    else if (fr == 0)
                        fr = 2;
                    break;
                }
            }
        }
        if (ba[y][x] == 0 && ba[y][x + 1] == 1) {
            for (int i = x + 2; i < 8; i++) {
                if (ba[y][i] == 0)
                    break;
                else if (ba[y][i] == 2) {
                    if (fr == 1)
                        fr = 3;
                    else if (fr == 0)
                        fr = 2;
                    break;
                }
            }
        }
        if (fr > 1)
            break;
    }
    for (int x = 7; x >= 2; x--) {
        if (ba[x][y] == 0 && ba[x - 1][y] == 1) {
            for (int i = x - 2; i >= 0; i--) {
                if (ba[i][y] == 0)
                    break;
                else if (ba[i][y] == 2) {
                    if (fr == 1)
                        fr = 3;
                    else if (fr == 0)
                        fr = 2;
                    break;
                }
            }
        }
        if (ba[y][x] == 0 && ba[y][x - 1] == 1) {
            for (int i = x - 2; i >= 0; i--) {
                if (ba[y][i] == 0)
                    break;
                else if (ba[y][i] == 2) {
                    if (fr == 1)
                        fr = 3;
                    else if (fr == 0)
                        fr = 2;
                    break;
                }
            }
        }
        if (fr > 1)
            break;
    }

}
for (int x = 0; x < 6; x++) {
    for (int y = 0; y < 6; y++) {
        if (ba[x][y] == 0 && ba[x + 1][y + 1] == 1) {
            for (int i = 2; i < 8; i++) {
                if (x + i > 8 || y + i > 8 || ba[x + i][y + i] == 0)
                    break;
                else if (ba[x + i][y + i] == 2) {
                    if (fr == 1)
                        fr = 3;
                    else if (fr == 0)
                        fr = 2;
                    break;
                }
            }
        }
    }
    for (int y = 7; y >= 2; y--) {
        if (ba[x][y] == 0 && ba[x + 1][y - 1] == 1) {
            for (int i = 2; i < 8; i++) {
                if (x + i > 8 || y - i <= 0 || ba[x + i][y - i] == 0)
                    break;
                else if (ba[x + i][y - i] == 2) {
                    if (fr == 1)
                        fr = 3;
                    else if (fr == 0)
                        fr = 2;
                    break;
                }
            }
        }
    }
    if (fr > 1)
        break;
}
for (int x = 7; x >= 2; x--) {
    for (int y = 0; y < 6; y++) {
        if (ba[x][y] == 0 && ba[x - 1][y + 1] == 1) {
            for (int i = 2; i < 8; i++) {
                if (x - i <= 0 || y + i > 8 || ba[x - i][y + i] == 0)
                    break;
                else if (ba[x - i][y + i] == 2) {
                    if (fr == 1)
                        fr = 3;
                    else if (fr == 0)
                        fr = 2;
                    break;
                }
            }
        }
    }
    for (int y = 7; y >= 2; y--) {
        if (ba[x][y] == 0 && ba[x - 1][y - 1] == 1) {
            for (int i = 2; i < 8; i++) {
                if (x - i <= 0 || y - i <= 0 || ba[x - i][y - i] == 0)
                    break;
                else if (ba[x - i][y - i] == 2) {
                    if (fr == 1)
                        fr = 3;
                    else if (fr == 0)
                        fr = 2;
                    break;
                }
            }
        }
    }
    if (fr > 1)
        break;
}

    
if (fr == 1 && *order % 2 == 0) {
    *order = *order - 1;
    return 2;
}
else if (fr == 2 && *order % 2 == 1) {
    *order = *order - 1;
    return 2;
}
else if (fr == 0) {
    *order = 0;
    return 0;
}
else if (fr == 3) 
    return 0;
}

int main(){
    float blpx, blpy, whpx, whpy;
    int a=1, path = 0, zen = 0, whan = 0, bhan = 0, e, b = 0, c = 0, order = 1, ban[8][8] =
   {0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,2,1,0,0,0,
    0,0,0,1,2,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0};
    VideoMode desktopMode = VideoMode::getDesktopMode();
    RenderWindow window(VideoMode(640,640), "SFML osero");
    Font font;
    if (!font.loadFromFile("MPLUS1p-Regular.ttf")) {
        return -1;
    }
    Text text;
    text.setFont(font);
    text.setString(L"黒が先行です\n(Escを押してください)");
    text.setCharacterSize(30);
    text.setFillColor(Color::White);
    FloatRect textb = text.getLocalBounds();
    text.setOrigin(textb.left+textb.width/2.0f, textb.top+textb.height/2.0f);
    Vector2u windows = window.getSize();
    text.setPosition(windows.x/2.0f,windows.y/2.0f);
    Text text2;
    text2.setFont(font);
    text2.setString(L"黒の勝ち");
    text2.setCharacterSize(100);
    text2.setFillColor(Color::Blue);
    FloatRect textb2 = text.getLocalBounds();
    text2.setOrigin(textb2.left + textb2.width / 2.0f, textb2.top + textb2.height / 2.0f);
    text2.setPosition(windows.x / 2.0f, windows.y / 2.0f);
    Text text3;
    text3.setFont(font);
    text3.setString(L"白の勝ち");
    text3.setCharacterSize(100);
    text3.setFillColor(Color::Blue);
    FloatRect textb3 = text.getLocalBounds();
    text3.setOrigin(textb3.left + textb3.width / 2.0f, textb3.top + textb3.height / 2.0f);
    text3.setPosition(windows.x / 2.0f, windows.y / 2.0f);
    Text text4;
    text4.setFont(font);
    text4.setString(L"同点");
    text4.setCharacterSize(140);
    text4.setFillColor(Color::Blue);
    FloatRect textb4 = text.getLocalBounds();
    text4.setOrigin(textb4.left + textb4.width / 2.0f, textb4.top + textb4.height / 2.0f);
    text4.setPosition(windows.x / 2.0f, windows.y / 2.0f);
    Text text5;
    text5.setFont(font);
    text5.setString(L"パス\n(Escを押してください)");
    text5.setCharacterSize(30);
    text5.setFillColor(Color::Black);
    FloatRect textb5 = text.getLocalBounds();
    text5.setOrigin(textb5.left + textb5.width / 2.0f, textb5.top + textb5.height / 2.0f);
    text5.setPosition(windows.x / 2.0f, windows.y / 2.0f);
    RectangleShape pathtile;
    pathtile.setSize(Vector2f(640.f, 640.f));
    pathtile.setPosition(0, 0);
    pathtile.setFillColor(Color::White);
    vector<RectangleShape> vtile;
    for (int i = 0; i < 8; i++) {
        for (int g = 0; g < 8; g++) {
            RectangleShape tile;
            tile.setSize(Vector2f(80.f, 80.f));
            if ((i + 1) % 2 != 0) {
                if ((g + 1) % 2 == 0) {
                    tile.setFillColor(Color(0, 128, 0));
                }
                else {
                    tile.setFillColor(Color(0, 110, 0));
                }
            }
            else if ((i + i) % 2 == 0) {
                if ((g + 1) % 2 != 0) {
                    tile.setFillColor(Color(0, 128, 0));
                }
                else {
                    tile.setFillColor(Color(0, 110, 0));
                }
            }
            tile.setPosition(i * 80.0f, g * 80.0f);
            vtile.push_back(tile);
        }
    }
    CircleShape black;
    CircleShape white;
    black.setFillColor(Color::Black);
    white.setFillColor(Color::White);
    black.setRadius(35.f);
    white.setRadius(35.f);
    black.setOrigin(black.getRadius(), black.getRadius());
    white.setOrigin(white.getRadius(), white.getRadius());
    // メインループ
    while (window.isOpen()){
        Event event;
        window.clear();
        while (window.pollEvent(event)){
            if (event.type == Event::Closed)
                window.close();  
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {
                    a = 0;
                }
            }
        }
        if (a == 2) {
            window.draw(pathtile);
            window.draw(text5);
        }
        else if (a==1) {
            window.draw(text); 
        }
        else if(a==0) {
            for (int i = 0; i < 64; i++) {
                window.draw(vtile[i]);
            }
            for (int i = 0; i < 8; i++) {
                for (int g = 0; g < 8; g++) {
                    if (ban[i][g] == 1) {
                        blpx = static_cast<float>((g + 1) * 80 - 40);
                        blpy = static_cast<float>((i + 1) * 80 - 40);
                        black.setPosition(blpx, blpy);
                        window.draw(black);
                    }
                    else if (ban[i][g] == 2) {
                        whpx = static_cast<float>((g + 1) * 80 - 40);
                        whpy = static_cast<float>((i + 1) * 80 - 40);
                        white.setPosition(whpx, whpy);
                        window.draw(white);
                    }
                }
            }
            if (event.type == Event::MouseButtonPressed) {
                Vector2i pt = Mouse::getPosition(window);
                for (b = 1; b < 9; b++) {
                    if (pt.y / (80 * b) == 0) {
                        b = b - 1;
                        break;
                    }
                }
                for (c = 1; c < 9; c++) {
                    if (pt.x / (80 * c) == 0) {
                        c = c - 1;
                        break;
                    }
                }
            }
            e = 0;
            if (ban[b][c] == 0) {
                column(ban, b, c, &order, &e);
                row(ban, b, c, &order, &e);
                cross(ban, b, c, &order, &e);
                if (e != 0) {
                    if (order % 2 == 1) {
                        ban[b][c] = 1;
                    }
                    else if (order % 2 == 0) {
                        ban[b][c] = 2;
                    }
                    order += 1;
                    a = han(ban, &order);
                }
            }

            if (order == 61 || order==0) {
                for (int i = 0; i < 8; i++) {
                    for (int g = 0; g < 8; g++) {
                        if (ban[i][g] == 1)
                            bhan = bhan + 1;
                        else if (ban[i][g] == 2)
                            whan = whan + 1;
                    }
                }
                if (bhan > whan) {
                    window.draw(text2);
                }
                else if (whan > bhan) {
                    window.draw(text3);
                }
                else if (whan == bhan) {
                    window.draw(text4);
                }
            }
        }
        window.display();
    }
    return 0;
}
