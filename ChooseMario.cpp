class ChooseMario {
public:
    void DrawMario(int marioY)
    {
        GotoXY(0, marioY);
        static bool leftArm = true;
        cout << "       %%%%%%      " << endl;
        cout << "     %%%%%%%%      " << endl;
        cout << "    %% %%% %%%%%   " << endl;
        cout << "    %% % % %%%     " << endl;
        cout << "   %%% %%% %%%%%   " << endl;
        cout << "   %%%%%%%%%%%%%%  " << endl;

        if (leftArm)
        {
            cout << "    %%%%   %%%%  %%" << endl;
            cout << "   %%%%%%%%%%%%%%  " << endl;
            cout << " %% %%%%%%%%%%%    " << endl;
            cout << "%%  %%%%%%%%%%%    " << endl;
            cout << "    %%%%%%%%%%%    " << endl;
            cout << "            %%%    " << endl;
            leftArm = false;
        }
        else
        {
            cout << "%%  %%%%   %%%%    " << endl;
            cout << "  %%%%%%%%%%%%%%%  " << endl;
            cout << "    %%%%%%%%%%%  %%" << endl;
            cout << "    %%%%%%%%%%%    " << endl;
            cout << "    %%%%%%%%%%%    " << endl;
            cout << "    %%%            " << endl;
            leftArm = true;
        }


    }
