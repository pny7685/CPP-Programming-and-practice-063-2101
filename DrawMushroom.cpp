//나무를 그리는 함수
void DrawMushroom(int mushroomX)
{
    GotoXY(mushroomX, MUSHROOM_ROOT_Y);
    cout << "   %%%%%%   ";
    GotoXY(mushroomX, MUSHROOM_ROOT_Y + 1);
    cout << "  %%%%%%%%  ";
    GotoXY(mushroomX, MUSHROOM_ROOT_Y + 2);
    cout << " %%%%%%%%%% ";
    GotoXY(mushroomX, MUSHROOM_ROOT_Y + 3);
    cout << "   %%%%%%   ";
    GotoXY(mushroomX, MUSHROOM_ROOT_Y + 4);
    cout << "    %%%%    ";

}
