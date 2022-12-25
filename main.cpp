//sea_battle

#include "includes.h" // ���������� ��� ������ �������

int main()
{
    setlocale(LC_ALL, "ru");
    std::random_device rd;
    std::mt19937 g(rd());
    srand(time(NULL));
    system("cls");
    Field field;
    char variant1[2][30] = { "AUTOMATIC PLACEMENT", "MANUAL PLACEMENT" };
    char variant2[2][30] = { "DUMB BOT", "SMART BOT" };
    int A = 0, change = 0, automaticPlacement = 1, smartBot = 0;
    int x = 1, y = 0;
    field.me.showField(0, 0, "me"); //������ ������� ����
    field.choice(variant1, change);
    int key;
    do //��������� ����
    {
        key = _getch(); //�������� ����� ������� �������
        switch (key) //��������� �����
        {
        case Keys::UP: //���� ������ "��������� �����"
            if (y > 0) //���� "y" ������ 0
            {
                y--; //�������� �� �������� �� "y" 1
                change = y; //��������� �����
                field.choice(variant1, change); //����� ������� �� �����
            }
            break;
        case Keys::DOWN: //���� ������ "��������� ����"
            if (y < 1) //���� "y" ������ 1
            {
                y++; //���������� � �������� �� "y" 1
                change = y; //��������� �����
                field.choice(variant1, change); //����� ������� �� �����
            }
            break;
        case Keys::ENTER:
            do
            {
                switch (change)
                {
                case 0: // ���� 0
                    automaticPlacement = true; //�������������� �����������
                    A++; //����� ��������� ����
                    break;
                case 1:
                    automaticPlacement = false; //������ �����������
                    A++; //����� ��������� ����
                    y++; //���������� � �������� �� "y" 1
                    break;
                }
            } while (key != Keys::ENTER);
        }
    } while (A < 1);
    A = 0, change = 0;
    x = 1, y = 0;
    system("cls");

    field.me.showField(0, 0, "me"); //������ ������� ����
    field.choice(variant2, change);
    do //��������� ����
    {
        key = _getch(); //�������� ����� ������� �������
        switch (key) //��������� �����
        {
        case Keys::UP: //���� ������ "��������� �����"
            if (y > 0) //���� "y" ������ 0
            {
                y--; //�������� �� �������� �� "y" 1
                change = y; //��������� �����
                field.choice(variant2, change); //����� ������� �� �����
            }
            break;
        case Keys::DOWN: //���� ������ "��������� ����"
            if (y < 1) //���� "y" ������ 1
            {
                y++; //���������� � �������� �� "y" 1
                change = y; //��������� �����
                field.choice(variant2, change); //����� ������� �� �����
            }
            break;
        case Keys::ENTER:
            do
            {
                switch (change)
                {
                case 0: // ���� 0
                    smartBot = false; //�������������� �����������
                    A++; //����� ��������� ����
                    break;
                case 1:
                    smartBot = true; //������ �����������
                    A++; //����� ��������� ����
                    y++; //���������� � �������� �� "y" 1
                    break;
                }
            } while (key != Keys::ENTER);
        }
    } while (A < 1);
    A = 0;
    system("cls");

    if (automaticPlacement)
    {
        field.me.setShipsWithBot("me");
    }
    else
    {
        field.me.setShips();
    }
    field.enemy.setShipsWithBot("enemy");

    field.showFullField();
    int i = 2;
    for (;; ++i)
    {
        if (i % 2 == 0) { if (!field.myAttack()) { break; } }
        else
        {
            if (smartBot) { if (!field.smartEnemyAttack()) { break; } }
            else { if (!field.enemyAttack()) { break; }; }
        }
    }
    field.showFullField();
    setCursor(0, 15);
    if (i % 2 == 0) { std::cout << "YOU WON!!!\n"; }
    else { std::cout << "Your ships are destroyed, the enemy has won.\n"; }
    system("PAUSE");
    return 0;
}
