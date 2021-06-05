void DrawBar(int barX)
{
    GotoXY(barX, BAR_Y);
    cout << "================";
    GotoXY(barX, BAR_Y + 1);
    cout << "================";
}

bool isCrush_High(const int mushroomX, const int barX, const int marioY)
{
    //트리의 X가 공룡의 몸체쪽에 있을때,
    //공룡의 높이가 충분하지 않다면 충돌로 처리
    GotoXY(0, 0);


    cout << "mushroomX : " << mushroomX << "marioY : " << marioY << "barX : " << barX << endl;
    //이런식으로 적절한 X, Y를 찾습니다.
    if (mushroomX <= 6 && mushroomX >= 4 &&
        marioY > 7)
    {
        return true;
    }
    if (barX <= 6 && barX >= 1 && marioY < 5) {
        return true;
    }
    return false;
}
};
