void DrawBar(int barX)
{
    GotoXY(barX, BAR_Y);
    cout << "================";
    GotoXY(barX, BAR_Y + 1);
    cout << "================";
}

bool isCrush_High(const int mushroomX, const int barX, const int marioY)
{
    //Ʈ���� X�� ������ ��ü�ʿ� ������,
    //������ ���̰� ������� �ʴٸ� �浹�� ó��
    GotoXY(0, 0);


    cout << "mushroomX : " << mushroomX << "marioY : " << marioY << "barX : " << barX << endl;
    //�̷������� ������ X, Y�� ã���ϴ�.
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
