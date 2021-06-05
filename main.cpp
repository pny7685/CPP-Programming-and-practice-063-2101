#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include <iostream>

#define DINO_ROOT_Y 12
#define TREE_ROOT_Y 20
#define TREE_ROOT_X 45
#define ROCK_ROOT_X 45
#define ROCK_ROOT_Y 20

#define SONIC_ROOT_Y 16
#define TRAP_ROOT_Y 17
#define TRAP_ROOT_X 45
#define RING_ROOT_X 45
#define RING_ROOT_Y 5

#define MARIO_ROOT_Y 16
#define MUSHROOM_ROOT_X 45
#define MUSHROOM_ROOT_Y 19
#define BAR_X 45
#define BAR_Y 4

using namespace std;

int main() {
    SetGameScreen();


    while (true)        //게임 루프
    {
        //게임 시작시 초기화
        bool isJumping = false;
        bool isRoot = true;
        const int gravity = 3;

        int dinoY = DINO_ROOT_Y;
        int sonicY = SONIC_ROOT_Y;
        int marioY = MARIO_ROOT_Y;
        int mushroomX = MUSHROOM_ROOT_X;
        int treeX = TREE_ROOT_X;
        int rockX = ROCK_ROOT_X;
        int ringX = RING_ROOT_X;
        int trapX = TRAP_ROOT_X;
        int mushroomY = MUSHROOM_ROOT_Y;
        int barX = BAR_X;
        int barY = BAR_Y;

        int score = 0;
        clock_t start, curr;    //점수 변수 초기화
        start = clock();        //시작시간 초기화

        int input_key;
        Selectcharacter();
        input_key = _getch();  //_getch함수는 cin과 달리 입력과 동시에 적용된다.
        switch (input_key) {
        case 51: // ASCII코드로 51은 3을 의미
            ChooseMario C;
            while (true)    //한 판에 대한 루프
            {
                //충돌체크 버섯의 x값,바의 x값과 마리오의 y값으로 판단
                if (C.isCrush_High(mushroomX, barX, marioY))
                    break;


                /*if (C.isCollision_High(barX, marioY)) {
                    break;
                }*/



                //z키가 눌렸고, 바닥이 아닐때 점프
                if (GetKeyDown() == 'z' && isRoot)
                {
                    isJumping = true;
                    isRoot = false;
                }

                //점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
                if (isJumping)
                {
                    marioY -= gravity;
                }
                else
                {
                    marioY += gravity;

                }

                //Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
                if (marioY >= MARIO_ROOT_Y)
                {
                    marioY = MARIO_ROOT_Y;
                    isRoot = true;
                }

                //버섯이 왼쪽으로 (x음수) 가도록하고
                //버섯의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
                mushroomX -= 3;
                if (mushroomX <= 0)
                {
                    mushroomX = MUSHROOM_ROOT_X;
                }

                if (barX < 20) // bar가 일정 거리이상 가까워지면 속도가 빨라지게 함.
                    barX -= 4;
                else
                    barX -= 2;
                if (barX <= 0)
                {
                    barX = BAR_X;
                }




                //점프의 맨위를 찍으면 점프가 끝난 상황.
                if (marioY <= 3)
                {
                    isJumping = false;
                }

                C.DrawMario(marioY);        //draw dino
                C.DrawMushroom(mushroomX);
                C.DrawBar(barX);

                
                curr = clock();            //현재시간 받아오기
                if (((curr - start) / CLOCKS_PER_SEC) >= 1)    // 1초가 넘었을떄
                {
                    score++;    //스코어 UP
                    start = clock();    //시작시간 초기화
                }
                Sleep(60);
                system("cls");    //clear

            //점수출력을 1초마다 해주는것이 아니라 항상 출력해주면서, 1초가 지났을때 ++ 해줌
                GotoXY(22, 0);    //커서를 가운데 위쪽으로 옮긴다. 콘솔창이 cols=100이니까 2*x이므로 22정도 넣어줌
                cout << "Score : " << score << endl;      //점수 출력해줌.
            }
            break;
        }
        //게임 오버 메뉴
        DrawYouDied(score);
    }
    return 0;
}