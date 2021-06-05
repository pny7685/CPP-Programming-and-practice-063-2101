void DrawYouDied(const int score)
{
    system("cls");
    int x = 18;
    int y = 8;
    GotoXY(x, y);
    cout << "===========================";
    GotoXY(x, y + 1);
    cout << "======Y O U   D I E D======";
    GotoXY(x, y + 2);
    cout << "===========================";
    GotoXY(x, y + 5);
    cout << "SCORE : " << score;

    cout << "\n\n\n\n\n\n\n\n\n";
    system("pause");
}
