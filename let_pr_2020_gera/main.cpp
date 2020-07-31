#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <Windows.h>

using namespace std;

void deliter(int*** array, int K, int N) // �������� �������
{
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;
}

void all_elements(int* mass_number, int P, int N, int M)
{
    //int quantity_0 = (P * N * M) / 100; // ���������� 0 � ������ �������

    //for (int i = 0; i < N * M; i++) // ��������� ������ ����������
    //{
    //    if (quantity_0 != 0) // ������� ���������� ��� ����
    //    {
    //        mass_number[i] = 0;
    //        quantity_0--;
    //    }
    //    else
    //    {
    //        mass_number[i] = 1; // ��������� ��������� ���������
    //    }
    //}

    __asm
    {
        mov eax, P // ��������� P
        mul N // ��������� P �� N
        mul M // P * N * M
        mov ebx, 100 // ��������� 100
        div ebx // P * N * M / 100
        mov ebx, eax // ������ � ebx ��������� quantity_0

        mov eax, N // ��������� N
        mul M // ��������� �� M
        mov edx, eax // ������ � edx ��������� N * M (���������� ���������)

        xor ecx, ecx // �������� ecx
        mov esi, mass_number // � esi ������ ������ ������� mass_number

        start : // ���������� �������� �������� �������
        cmp ecx, edx // ���������� ������� � ����������� ���������
            je End // ���� ��� �����, ������ �� ������ ��� ��������
            cmp ebx, 0 // ���� �� �����, ���������� ������� ����� � �����
            je one // ���� ������� ����� ����� ���� ��������� �� one

            xor eax, eax // �������� eax
            mov[esi], eax // ������ 0 � ������� ������� �������
            dec ebx // ��������� ������� �����
            jmp finish // ��������� �� finish

            one : // ���������� �������� �������� ������� ��������
        mov eax, 1 // ��������� 1
            mov[esi], eax // ������� ������� ������� ����� 1

            finish : // � ����� ������ ����������...
        add esi, 4 // ����������� ������ �������� �������� �� 4, ��� ��� � ��� int
            inc ecx // ����������� �������, ��� ��� ��������� ����� �������
            jmp start // ������������ ����� ��������� ��������� �������

            End : // ��� �������� ���������
    }

    for (int i = N * M - 1; i >= 1; i--) // ������������ ��� �������� �������
    {
        int j = 0 + rand() % (i + 1); // �������� ��������� ������

        int tmp = mass_number[j];
        mass_number[j] = mass_number[i];
        mass_number[i] = tmp;
    }
}

void creator(int*** array, int K, int N, int M) // ��������� ������ � ������������ �������
{
    for (int i = 0; i < K; i++) // i - ������ ������� �������
    {
        array[i] = new int* [N]; // ��������� ������ ��� N ����� � ������ �������
        for (int j = 0; j < N; j++)
        {
            array[i][j] = new int[M]; // ��������� ������ ��� M �������� � ������ �������
        }
    }
}

void zeros_finder(int*** array_copy, int& tek, int& i, int& j, int& k, int M, int N, int*** mas_tek) // ����� �����
{
    if (j != 0 && array_copy[i][j - 1][k] == 0) // ���� �� ��������� �� �� ����� ������ ������, c������ ������� ������
    {
        if (++tek < 3480)
        {
            array_copy[i][j - 1][k] = 1;

            mas_tek[i][j - 1][k] = 1;

            int new_j = j - 1;
            zeros_finder(array_copy, tek, i, new_j, k, M, N, mas_tek);
        }
        else
        {
            return;
        }
    }

    if (k != (M - 1) && array_copy[i][j][k + 1] == 0) // ���� �� ��������� �� �� ����� ������ ������, c������ ������� ������
    {
        if (++tek < 3480)
        {
            array_copy[i][j][k + 1] = 1;

            mas_tek[i][j][k + 1] = 1;

            int new_k = k + 1;
            zeros_finder(array_copy, tek, i, j, new_k, M, N, mas_tek);
        }
        else
        {
            return;
        }
    }

    if (j != (N - 1) && array_copy[i][j + 1][k] == 0) //  // ���� �� ��������� �� �� ����� ������ ������, c������ ������� �����
    {
        if (++tek < 3480)
        {
            array_copy[i][j + 1][k] = 1;

            mas_tek[i][j + 1][k] = 1;

            int new_j = j + 1;
            zeros_finder(array_copy, tek, i, new_j, k, M, N, mas_tek);
        }
        else
        {
            return;
        }
    }

    if (k != 0 && array_copy[i][j][k - 1] == 0) //  // ���� �� ��������� �� �� ����� ����� ������, c������ ������� �����
    {
        if (++tek < 3480)
        {
            array_copy[i][j][k - 1] = 1;

            mas_tek[i][j][k - 1] = 1;

            int new_k = k - 1;
            zeros_finder(array_copy, tek, i, j, new_k, M, N, mas_tek);
        }
        else
        {
            return;
        }
    }
}

int result(int*** array_copy, int i, int K, int N, int M, int*** mas_max_cnt, int& repit) // ������� ���������� ����������� �����
{
    int max_cnt = 0; // ������������ ���������� ����������� �����

    int*** mas_tek = new int** [K]; // ������ � ������� ����� �������� ��������� ��������� ����� �� ������� �����
    creator(mas_tek, K, N, M); // �������� � ��� ������

    for (int j = 0; j < N; j++)
    {
        for (int k = 0; k < M; k++)
        {
            if (array_copy[i][j][k] == 0) // ����� ����� �����
            {
                for (int iq = 0; iq < K; iq++)
                {
                    for (int jq = 0; jq < N; jq++)
                    {
                        for (int kq = 0; kq < M; kq++)
                        {
                            mas_tek[iq][jq][kq] = 0; // �������� ������
                        }
                    }
                }

                int tek = 1; // ���������� ����� � ������� �����
                mas_tek[i][j][k] = 1; // �������� ���� ���� � ����� �������

                array_copy[i][j][k] = 1; // ����� ������ �� ������� ���� ���� �������� ��� �� 1

                zeros_finder(array_copy, tek, i, j, k, M, N, mas_tek); // �������� ����������� �������, ������� �������� ���� �� ������ ����� ���� ������
                if (tek >= 3480)
                {
                    return -1;
                }
                else if (tek > max_cnt) // ���� � ������� ����� ����� ������ ��� � ������������ ����� �� �����...
                {
                    repit = 1; // ���������� ����� ����� � ���������� �����������
                    max_cnt = tek; // ������� ����� ���������� ������������

                    for (int i = 0; i < K; i++)
                    {
                        for (int j = 0; j < N; j++)
                        {
                            for (int k = 0; k < M; k++)
                            {
                                mas_max_cnt[i][j][k] = mas_tek[i][j][k]; // �������������� �� �������� ������� � ������������
                            }
                        }
                    }
                }
                else if (tek == max_cnt) // ���� ���������, ��� � ����� �� ����������� ���� ��� ���� �����...
                {
                    repit++; // ����������� ��� ����������
                    for (int i = 0; i < K; i++)
                    {
                        for (int j = 0; j < N; j++)
                        {
                            for (int k = 0; k < M; k++)
                            {
                                mas_max_cnt[i][j][k] = mas_max_cnt[i][j][k] + mas_tek[i][j][k]; // �� ����� ������ ������������, ��� ��� �������� ������ ������ �����
                            }
                        }
                    }
                }
            }
        }
    }
    deliter(mas_tek, K, N); // mas_tek ������ �� �����
    return max_cnt;
}

void filling(int*** array, int* mass_number, int K, int N, int M, int P)
{
    ofstream fout;
    fout.open("gera_test.txt", ios_base::app);
    if (!fout.is_open())
    {
        cout << "���� �� ����� ���� ������!" << endl;
    }
    else
    {
        fout << "K = " << K << endl << "N = " << N << endl << "M = " << M << endl << "P = " << P << endl << endl;
        for (int i = 0; i < K; i++) // ���� �� ������ �������
        {
            int* mass_index = new int[N * M]; // ������ ������������ ��������...

            for (int i = 0; i < N * M; i++) // ���������...
            {
                mass_index[i] = -1; // ������������� ��������� ����� �� ���������� � ��������
            }
            int ind = 0; // ������ ������� ��������

            int left = 0; // ����� ������� ������� ���������
            int right = N * M - 1; // ������ ������� ������� ���������

            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < M; k++)
                {
                    int error; // ������� ����, ��� ��������� ������ ��� ��� �����������
                    int index; // ������ ������� ���� ��������� ��������� ������
                    do
                    {
                        error = 0; // ���������� ������� ������

                        index = left + rand() % (right - left + 1); // ������� ��������� �������� �������� ������� (+1, ��� ��� right ��� ������)

                        for (int i = 0; i < N * M && mass_index[i] != -1; i++) // ��������� �� ����� ������� ��������
                        {
                            if (mass_index[i] == index) // ���� ��������, ��� ��������� ������ ��� ����������...
                            {
                                error = 1; // ��������� ����
                                break; // � ����� �������
                            }
                        }
                    } while (error == 1); // ����� ��������� ���� �� ������ ���������� ������

                    int flag; // ������� ����, ��� ������� ���� �������
                    if (index == left && left != right) // ���� ��������� ����� ��������� � ����� ��������...
                    {
                        left++; // ����� ������� ��������
                        do
                        {
                            flag = 0; // ���������� ����
                            for (int i = 0; i < N * M && mass_index[i] != -1; i++) // ������� �� ���� �������...
                            {
                                if (mass_index[i] == left) // ���� �� ��� ����� ����� �������
                                {
                                    left++; // ���� ����, �� ����� ������� ��������
                                    flag = 1; // ���� �����������
                                    break; // ��� ������ ���������� ����
                                }
                            }
                        } while (flag != 0); // ���� ������� ����������, �� ���� ��������� �����
                    }

                    if (index == right && left != right) // ���� ��������� ����� ������� � ������ ��������
                    {
                        right--; // ������� ������ �������
                        do
                        {
                            flag = 0; // ���������� ����
                            for (int i = 0; i < N * M && mass_index[i] != -1; i++) // ��������� �� ����� ������� ��������
                            {
                                if (mass_index[i] == right) // ���� ����� ������ �������
                                {
                                    right--; // ������� ��
                                    flag = 1; // ���� ���������
                                    break; // ������� ����������, ���� ������ ���� ������
                                }
                            }
                        } while (flag != 0); // ���� �� �������� ��� ������� �� ��������
                    }

                    mass_index[ind++] = index; // ��� ��� ���� ������ �� ���� �� ���������� - ���������� ���

                    array[i][j][k] = mass_number[index]; // �� ����� ������� ���� ��� ���� �������� ��������� � �������
                    fout << array[i][j][k] << " "; // ����� � ����
                }
                fout << endl; // ��������� ������ ������� enter � ����
                if (j == 0)
                {
                    cout << "������ � " << j + 1 << " ������� " << i + 1 << " ���������";
                }
                else
                {
                    cout << "\r" << "������ � " << j + 1 << " ������� " << i + 1 << " ���������";
                }
            }
            delete[] mass_index; // ������� ������ ��������, ��� ��� ��� ������ � ������� �������� �� ������ �� �����
            fout << endl;
            cout << "\r                                       \r";
        }
        fout.close();
    }
}

void input(int*** array, int*** array_copy, int K, int N, int M, int P) // ���� � ���� � �����������
{
    ofstream fout2;
    fout2.open("gera_test1.txt", ios_base::app);
    if (!fout2.is_open())
    {
        cout << "���� �� ����� ���� ������!" << endl;
    }
    else
    {
        ifstream fin("gera_test.txt"); // ������� ���� ��� ������
        if (!fin.is_open())
        {
            cout << "���� �� ����� ���� ������!" << endl;
        }
        else
        {
            string line; // ������� ������

            fout2 << "K = " << K << endl << "N = " << N << endl << "M = " << M << endl << "P = " << P << endl << endl;

            int in = 4; // ������ 4 ������� ����������
            while (in >= 0)
            {
                if (in > 0)
                {
                    in--;
                    int a;
                    char space;
                    fin >> space >> space >> a;
                }
                else
                {
                    in--;
                    for (int i = 0; i < K; i++) // ���� �� ������ �������
                    {
                        for (int j = 0; j < N; j++)
                        {
                            for (int k = 0; k < M; k++)
                            {
                                fin >> array[i][j][k]; // ���� �� ����� � �������
                                fout2 << array[i][j][k] << " "; // ����� � ����
                                array_copy[i][j][k] = array[i][j][k]; // � � �����
                            }
                            fout2 << endl; // ����� � ����
                            getline(fin, line);
                        }

                        int*** mas_max_cnt = new int** [K]; // ������ ��� ���������� ��������� ������������ �����
                        creator(mas_max_cnt, K, N, M); // �������� � ��� ������
                        int repit = 1; // �����������, ��� ���������� ���� �� ���� �����
                        int zero = result(array_copy, i, K, N, M, mas_max_cnt, repit); // ������ ���������� ����� � ������������ ����� � ���������� ����� �����

                        for (int j = 0; j < N; j++)
                        {
                            for (int k = 0; k < M; k++)
                            {
                                if (mas_max_cnt[i][j][k] == 1 && zero != 1 && zero != -1) // ���� �� ������� ������ � ������� ����� ������� � ��� ��� �� ����� ��� ���� � ����� �� ����
                                {
                                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4)); // ������������ ���� �� �����
                                    cout << array[i][j][k] << " "; // ����� �� �����
                                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7)); // ���������� ������ �����
                                }
                                else if (array[i][j][k] == 0) // ���� ������� ������� �� �� ����� 0
                                {
                                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 3)); // ������������ ���� ����
                                    cout << array[i][j][k] << " "; // ����� �� �����
                                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7)); // ���������� ������ �����
                                }
                                else // ���� ��� 1
                                {
                                    cout << array[i][j][k] << " "; // ����� �� �����
                                }
                            }
                            cout << endl; // ��������� ������ ������� enter �� �����
                        }

                        deliter(mas_max_cnt, K, N); // ���� ������ ������ �� �����

                        if (zero == -1)
                        {
                            cout << "����� ����������� ���� � ����� ������ 3480. �������� ������������ �����." << endl << endl; // ��������� ������� ������� ������ enter �� �����
                            fout2 << "����� ����������� ���� � ����� ������ 3480. �������� ������������ �����." << endl << endl; // ��������� ������� ������� ������ enter � ����
                        }
                        else if (zero == 1)
                        {
                            cout << "��� ����������� ���� � ����� �����" << endl << endl; // ��������� ������� ������� ������ enter �� �����
                            fout2 << "��� ����������� ���� � ����� �����" << endl << endl; // ��������� ������� ������� ������ enter � ����
                        }
                        else if (zero == 0)
                        {
                            cout << "������� ������� ������ �� ������" << endl << endl; // ��������� ������� ������� ������ enter �� �����
                            fout2 << "������� ������� ������ �� ������" << endl << endl; // ��������� ������� ������� ������ enter � ����
                        }
                        else
                        {
                            cout << "������������ ���������� ����� ����������� ���� � ����� = " << zero << endl; // ��������� ������� ������� ������ enter �� �����
                            cout << "����� ����� ��������� � ������� = " << repit << endl << endl;
                            fout2 << "������������ ���������� ����� ����������� ���� � ����� = " << zero << endl << endl; // ��������� ������� ������� ������ enter � ����
                        }
                        getline(fin, line);
                    }
                }
            }
            fout2.close();
        }
        fin.close();
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    int N; // ���������� �����
    int M; // ���������� ��������
    int K; // ���������� �������� ������
    int P; // ������� �����

    ofstream fout;
    fout.open("gera_test.txt", ios_base::trunc); // ������� ������ ���������� �����
    if (!fout.is_open())
    {
        cout << "���� �� ����� ���� ������!" << endl;
    }
    else
    {
        fout.close();
        ofstream fout3;
        fout3.open("gera_test1.txt", ios_base::trunc); // ������� ������ ���������� �����
        if (!fout3.is_open())
        {
            cout << "���� �� ����� ���� ������!" << endl;
        }
        else
        {
            fout3.close();

            cout << "������� K (���������� �������� ������) ";
            cin >> K;

            cout << "������� N (���������� �����) ";
            cin >> N;

            cout << "������� M (���������� ��������) ";
            cin >> M;

            cout << "������� ������� ����� ";
            cin >> P;

            cout << "����� � ������ ������� " << N * M << " ���������" << endl;
            cout << "����� � ������ ������� " << ((P * N * M) / 100) << " �����" << endl;
            cout << "����� � ������ ������� " << (N * M) - ((P * N * M) / 100) << " ������" << endl << endl;

            int* mass_number = new int[N * M]; // ������ � ������� ��������� ��� ��������� �������� ������
            all_elements(mass_number, P, N, M); // ��������� ���� ������

            int*** array = new int** [K]; // ������ ���� ������
            creator(array, K, N, M); // �������� ������ ��� ��� �������

            filling(array, mass_number, K, N, M, P); // ���������� ������ ���������� ����������

            delete[] mass_number; // ������� ������ ���������, ��� ��� ��� ������� ��� ���������

            deliter(array, K, N); // �������� �������

            /*�������� ���������� ����� ����� �� �� �����*/
            N = 0; // ���������� �����
            M = 0; // ���������� ��������
            K = 0; // ���������� �������� ������
            P = 0; // ������� �����

            ifstream fin("gera_test.txt"); // ������� ���� ��� ������
            if (!fin.is_open())
            {
                cout << "���� �� ����� ���� ������!" << endl;
            }
            else
            {
                char space; // ������ ������ ��� ����������� ����������
                /*��������� ����������*/
                fin >> space >> space >> K;
                fin >> space >> space >> N;
                fin >> space >> space >> M;
                fin >> space >> space >> P;

                int*** array = new int** [K]; // ������ ���� ������
                int*** array_copy = new int** [K]; // ����� ������� ���� ������
                creator(array, K, N, M); // �������� ������ ��� ��� ������� � ��� �� �����
                creator(array_copy, K, N, M); // �������� ������ ��� ��� ������� � ��� �� �����

                input(array, array_copy, K, N, M, P); // ���� � �������� ���� ������ � �����������

                deliter(array_copy, K, N); // �������� ������� � ��� �����
                deliter(array, K, N); // �������� ������� � ��� �����

                fin.close();
            }
        }
    }
    return 0;
}