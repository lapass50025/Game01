#include <iostream>
#include <stdlib.h>

#define ROWS 15
#define COLS 60

using namespace std;



// 주인공 정보
struct _human
{
    int x;
    int y;
    int survival;
    char display;
};

// 적들의 정보
struct _enemy
{
    int x;
    int y;
    int survival;
    char display;
};

// 초기값
struct _human man = { 10, 10, 1, '@'};
struct _enemy enemy[10] = {
                    {1, 1, 1, '&'},
                    {10, 20, 1, '#'},
                    {7, 43, 1, '#'},
                    {2, 34, 1, '%'},
                    {15, 5, 1, '&'},
                    {4, 18, 1, '&'},
                    {9, 29, 1, '%'},
                    {3, 2, 1, '&'},
                    {1, 27, 1, '%'},
                    {10, 21, 1, '&'}
};

// 주인공과 상대편 정보를 출력하기
void ShowInformation(void)
{
    int i = 0;
    cout << "[ 주인공 ] " << "X : " << man.x << ", Y : " << man.y << ", 생존여부 : " << man.survival << ", 표시 : " << man.display << endl;

    for (i = 0; i < 10; i++)
    {
        cout << "[ 상대 ] " << "X : " << enemy[i].x << ", Y : " << enemy[i].y << ", 생존여부 : " << enemy[i].survival << ", 표시 : " << enemy[i].display << endl;
    }
}

// 주인공과 상대편 정보를 변경하기
void ChangeInformation(void)
{
    int i = 0;
    int n = 0;

    // -1부터 1까지 랜덤 값 얻기
    n = rand() % 2 - 1;
    man.x = man.x + n;
    n = rand() % 2 - 1;
    man.y = man.y + n;

    for (i = 0; i < 10; i++)
    {
        // -1부터 1까지 랜덤 값 얻기
        n = rand() % 2 - 1;
        enemy[i].x = enemy[i].x + n;
        n = rand() % 2 - 1;
        enemy[i].y = enemy[i].y + n;
    }
}

// 주인공과 상대편 정보를 사각형 박스에 출력하기
void Display(void)
{
    int i = 0;
    int j = 0;
    int k = 0;

    // *************************** 표시하기
    for (i = 0; i < COLS; i++)
    {
        cout << "*";
    }
    cout << "\n";

    // 사각형 출력하기
    for (i = 0; i < ROWS; i++)
    {        
        for (j = 0; j < COLS; j++)
        {
            // 첫 번째 칸에 '*' 표시
            if( j == 0)
            {
                cout << "*";
            }
            else
            {
                // 주인공 정보 출력하기
                if( (man.x == i) && (man.y == j) )
                {
                    cout << man.display;
                    j = j + 1;
                }

                // 적들 정보 출력하기
                for( k = 0; k < 10; k++)
                {
                    if( (enemy[k].x == i) && (enemy[k].y == j) )
                    {
                        cout << enemy[k].display;
                        j = j + 1;
                    }
                }
                if( j < COLS )
                {
                    cout << " ";
                }
            }
        }

        // 마지막 번째 칸에 '*' 표시
        if( j == COLS )
        {
            cout << "*";
        }
        cout << "\n";
    }
    // *************************** 표시하기
    for (i = 0; i < COLS; i++)
    {
        cout << "*";
    }
}
int main(void)
{
    char ch = 'Y';

    while (ch == 'y' || ch == 'Y')
    {
        ShowInformation();
        Display();
        ChangeInformation();

        cout << "\n";
        cout << "continue? : ";
        cin >> ch;
    }

    cout << endl;
    return 0;
}