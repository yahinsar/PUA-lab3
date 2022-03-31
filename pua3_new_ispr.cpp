#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int CharInt(int N, char c, vector <char> mnojestvo) {
    for (int i = 0; i < N; i++)
    {
        if (mnojestvo[i] == c)
            return i;
    }
}

bool proverka_Ass(int N, char** keli, vector <char> mnojestvo) {
    bool prov = true;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            for (int z = 0; z < N; z++)
            {
                if (keli[x][CharInt(N, keli[y][z], mnojestvo)] != keli[CharInt(N, keli[x][y], mnojestvo)][z])
                    prov = false;
            }
        }
    }
    return prov;
}

bool proverka_Komm(int N, char** keli, vector <char> mnojestvo) {
    bool prov = true;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            if (keli[x][y] != keli[y][x])
                prov = false;
        }
    }
    return prov;
}


bool proverka_Idem(int N, char** keli, vector <char> mnojestvo) {
    bool prov = true;
    for (int x = 0; x < N; x++)
    {
        if (keli[x][x] != mnojestvo[x])
            prov = false;
    }
    return prov;
}

bool proverka_Obr(int N, char** keli, vector <char> mnojestvo) {
    bool prov = true;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            if (keli[x][y] != 1 && keli[y][x] != 1)
                prov = false;
        }
    }
    return prov;
}

bool proverka_Dist(int N, char** keli1, char** keli2, vector <char> mnojestvo) {
    bool prov = true;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            for (int z = 0; z < N; z++)
            {
                if (keli1[x][CharInt(N, keli2[y][z], mnojestvo)] !=
                    keli2[CharInt(N, keli1[x][y], mnojestvo)][CharInt(N, keli1[x][z], mnojestvo)] ||
                    keli1[CharInt(N, keli2[y][z], mnojestvo)][x] !=
                    keli2[CharInt(N, keli1[y][x], mnojestvo)][CharInt(N, keli1[z][x], mnojestvo)])
                    prov = false;
            }
        }
    }
    return prov;
}

void proverka_1(int N, vector <char> mnojestvo, char** keli1, char** keli2) {

    cout << endl;
    //проверка на ассоциативность
        // пересечение
    if (proverka_Ass(N, keli1, mnojestvo) == true)
        cout << "Операция пересечения ассоциативна" << endl;
    else
        cout << "Операция пересечения не ассоциативна" << endl;
    // объединение
    if (proverka_Ass(N, keli2, mnojestvo) == true)
        cout << "Операция объединения ассоциативна" << endl;
    else
        cout << "Операция объединения не ассоциативна" << endl;

    cout << endl;
    //проверка на коммутативность
        // пересечение
    if (proverka_Komm(N, keli1, mnojestvo) == true)
        cout << "Операция пересечения коммутативна" << endl;
    else
        cout << "Операция пересечения не коммутативна" << endl;
    // объединение
    if (proverka_Komm(N, keli2, mnojestvo) == true)
        cout << "Операция объединения коммутативна" << endl;
    else
        cout << "Операция объединения не коммутативна" << endl;

    cout << endl;
    //проверка на идемпотентность
        // пересечение
    if (proverka_Idem(N, keli1, mnojestvo) == true)
        cout << "Операция пересечения идемпотентна" << endl;
    else
        cout << "Операция пересечения не идемпотентна" << endl;
    // объединение
    if (proverka_Idem(N, keli2, mnojestvo) == true)
        cout << "Операция объединения идемпотентна" << endl;
    else
        cout << "Операция объединения не идемпотентна" << endl;

    cout << endl;
    //проверка на обратимость
        // пересечение
    if (proverka_Obr(N, keli1, mnojestvo) == true)
        cout << "Операция пересечения обратима" << endl;
    else
        cout << "Операция пересечения не обратима" << endl;
    // объединение
    if (proverka_Obr(N, keli2, mnojestvo) == true)
        cout << "Операция объединения обратима" << endl;
    else
        cout << "Операция объединения не обратима" << endl;

    cout << endl;
    //проверка на дистрибутивность
    if (proverka_Dist(N, keli1, keli2, mnojestvo) == true)
        cout << "Операция дистрибутивна" << endl;
    else
        cout << "Операция не дистрибутивна" << endl;

    cout << endl;
}

void bin_otn_two(int N, bool** matrix1, bool** matrix2, int bo_vvod) {

    cout << endl;
    if (bo_vvod == 1) {     //операция объединения
        bool** matrix_res;
        matrix_res = new bool* [N];
        for (int i = 0; i < N; i++) {
            matrix_res[i] = new bool[N];
            for (int j = 0; j < N; j++) {
                if (matrix1[i][j] == 1 || matrix2[i][j] == 1)
                    matrix_res[i][j] = 1;
                else
                    matrix_res[i][j] = 0;
            }
        }
        cout << "Итоговая матрица: " << endl << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << matrix_res[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (bo_vvod == 2) { //операция пересечения
        bool** matrix_res;
        matrix_res = new bool* [N];
        for (int i = 0; i < N; i++) {
            matrix_res[i] = new bool[N];
            for (int j = 0; j < N; j++) {
                if (matrix1[i][j] == 0 || matrix2[i][j] == 0)
                    matrix_res[i][j] = 0;
                else
                    matrix_res[i][j] = 1;
            }
        }
        cout << "Итоговая матрица: " << endl << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << matrix_res[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (bo_vvod == 4) { //операция произведения
        bool** matrix_res;
        matrix_res = new bool* [N];
        for (int i = 0; i < N; i++) {
            matrix_res[i] = new bool[N];
            for (int j = 0; j < N; j++) {
                matrix_res[i][j] = 0;
                for (int k = 0; k < N; k++) {
                    if (matrix1[i][k] == 1 && matrix2[k][j] == 1)
                        matrix_res[i][j] += 1;
                }
            }
        }
        cout << "Итоговая матрица: " << endl << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << matrix_res[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void bin_otn_one(int N, bool** matrix, int bo_vvod) {

    cout << endl;
    if (bo_vvod == 3) {     //операция дополнения
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == 1)
                    matrix[i][j] = 0;
                else
                    matrix[i][j] = 1;
            }
        }
        cout << "Итоговая матрица: " << endl << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (bo_vvod == 5) { //операция нахождения обратного
        bool** matrix_res;
        matrix_res = new bool* [N];
        for (int i = 0; i < N; i++) {
            matrix_res[i] = new bool[N];
            for (int j = 0; j < N; j++) {
                matrix_res[i][j] = matrix[j][i];
            }
        }
        cout << "Итоговая матрица: " << endl << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << matrix_res[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void matr_two(int N1, int M1, int** matrix1, int N2, int M2, int** matrix2, int mat_vvod, int mat_mod) {

    cout << endl;
    if (mat_vvod == 1) {     // сложение матриц
        if (N1 != N2 || M1 != M2) {
            cout << "Нельзя выполнить операцию сложения" << endl;
            return;
        }
        else {
            int** matrix_res;
            matrix_res = new int* [N1];
            for (int i = 0; i < N1; i++) {
                matrix_res[i] = new int[M1];
                for (int j = 0; j < M1; j++) {
                    matrix_res[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            cout << "Итоговая матрица: " << endl << endl;
            for (int i = 0; i < N1; i++) {
                for (int j = 0; j < M1; j++) {
                    cout << matrix_res[i][j] % mat_mod << " ";
                }
                cout << endl;
            }
        }

    }
    else if (mat_vvod == 2) {     // умножение матриц
        if (M1 != N2) {
            cout << "Нельзя выполнить операцию умножения" << endl;
            return;
        }
        else {
            int** matrix_res;
            matrix_res = new int* [N1];
            for (int i = 0; i < N1; i++) {
                matrix_res[i] = new int[M2];
                for (int j = 0; j < M2; j++) {
                    matrix_res[i][j] = 0;
                    for (int k = 0; k < M1; k++)
                        matrix_res[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
            cout << "Итоговая матрица: " << endl << endl;
            for (int i = 0; i < N1; i++) {
                for (int j = 0; j < M2; j++) {
                    cout << matrix_res[i][j] % mat_mod << " ";
                }
                cout << endl;
            }
        }
    }
}

int opred(int** matrix, int N1, int mat_mod) {
    if (N1 == 2) {
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    }
    else if (N1 == 1)
        return matrix[0][0];
    else if (N1 >= 3) {
        int** matrix_dop;
        matrix_dop = new int* [N1 - 1];
        for (int i = 0; i < N1 - 1; i++) {
            matrix_dop[i] = new int[N1 - 1];
        }
        int det = 0;
        int a, b;

        for (int j = 0; j < N1; j++) {
            a = 0;
            for (int k = 1; k < N1; k++) {
                b = 0;
                for (int s = 0; s < N1; s++) {
                    if (s != j) {
                        matrix_dop[a][b] = matrix[k][s];
                        b++;
                    }
                }
                a++;
            }
            det += pow(-1, j + 2) * matrix[0][j] * opred(matrix_dop, N1 - 1, mat_mod);
        }
        while (det < 0)
            det += mat_mod;
        det = det % mat_mod;
        return det;
    }
}

void delete_str_sto(int** matr, int n, int** temp_matr, int str, int sto)
{
    int ki = 0;
    for (int i = 0; i < n; i++) {
        if (i != str) {
            for (int j = 0, kj = 0; j < n; j++) {
                if (j != sto) {
                    temp_matr[ki][kj] = matr[i][j];
                    kj++;
                }
            }
            ki++;
        }
    }
}

void matr_one(int N1, int M1, int** matrix, int mat_vvod, int mat_mod) {

    cout << endl;
    if (mat_vvod == 3) {     // транспонирование матрицы
        int** matrix_res;
        matrix_res = new int* [M1];
        for (int i = 0; i < M1; i++) {
            matrix_res[i] = new int[N1];
            for (int j = 0; j < N1; j++) {
                matrix_res[i][j] = matrix[j][i];
            }
        }
        cout << "Транспонированная матрица: " << endl << endl;
        for (int i = 0; i < M1; i++) {
            for (int j = 0; j < N1; j++) {
                cout << matrix_res[i][j] % mat_mod << " ";
            }
            cout << endl;
        }
    }
    else if (mat_vvod == 4) {     // обращение матрицы
        if (N1 != M1) {
            cout << "Нельзя выполнить операцию обращения, должна быть квадратная матрица" << endl;
            return;
        }
        else {
            double** obr_matr;
            obr_matr = new double* [N1];
            for (int i = 0; i < N1; i++) {
                obr_matr[i] = new double[N1];
            }
            int determ = opred(matrix, N1, mat_mod);

            int obr_determ;
            for (int i = 1; i < 100000; ++i)
                if ((i * determ) % mat_mod == 1)
                {
                    obr_determ = i;
                    break;
                }

            cout << "Определитель матрицы по модулю " << mat_mod << " = " << determ << endl << endl;
            if (determ) {
                for (int i = 0; i < N1; i++) {
                    for (int j = 0; j < N1; j++) {
                        int m = N1 - 1;
                        int** temp_matr = new int* [m];
                        for (int k = 0; k < m; k++)
                            temp_matr[k] = new int[m];
                        delete_str_sto(matrix, N1, temp_matr, i, j);
                        int dop_el;
                        dop_el = pow(-1.0, i + j + 2) * opred(temp_matr, m, mat_mod);
                        while (dop_el < 0)
                            dop_el = dop_el + mat_mod;
                        dop_el = dop_el % mat_mod;
                        dop_el = dop_el * obr_determ;
                        obr_matr[i][j] = dop_el % mat_mod;
                    }
                }
            }
            else
                cout << "Определитель матрицы = 0, матрица вырожденная и обратной матрицы не имеет" << endl;


            int** matrix_transp;
            matrix_transp = new int* [N1];
            for (int i = 0; i < N1; i++) {
                matrix_transp[i] = new int[N1];
                for (int j = 0; j < N1; j++) {
                    matrix_transp[i][j] = obr_matr[j][i];
                }
            }
            cout << "Обратная матрица по модулю " << mat_mod << " : " << endl;
            for (int i = 0; i < N1; i++) {
                for (int j = 0; j < N1; j++) {
                    cout << matrix_transp[i][j] << " ";
                }
                cout << endl;
            }

            //ПРОВЕРКА
            cout << "Перемножим исходную матрицу и обратную, получим: " << endl;
            matr_two(N1, N1, matrix, N1, N1, matrix_transp, 2, mat_mod);
        }

    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    vector <char> mnojestvo;
    int sposob, i, j, N;
    cout << "Введите, что хотите сделать: " << endl;
    cout << "1 - проверить свойства операций " << endl;
    cout << "2 - выполнить операции над бинарными отношениями" << endl;
    cout << "3 - выполнить операции над матрицами (над конечным полем)" << endl;
    cin >> sposob;

    if (sposob == 1)
    {
        cout << "Введите размерность: " << endl;
        cin >> N;
        if (N == 0) {
            cout << "Ошибка";
            return 0;
        }
        cout << "Введите множество: " << endl;
        char vv;
        for (int i = 0; i < N; i++) {
            cin >> vv;
            mnojestvo.push_back(vv);
        }
        char** keli1;
        keli1 = new char* [N];
        cout << "Таблица Кэли операции пересечения: " << endl;
        for (int i = 0; i < N; i++) {
            keli1[i] = new char[N];
            for (int j = 0; j < N; j++) {
                cin >> keli1[i][j];
            }
        }
        char** keli2;
        keli2 = new char* [N];
        cout << "Таблица Кэли операции объединения: " << endl;
        for (int i = 0; i < N; i++) {
            keli2[i] = new char[N];
            for (int j = 0; j < N; j++) {
                cin >> keli2[i][j];
            }
        }
        proverka_1(N, mnojestvo, keli1, keli2);
    }
    else if (sposob == 2)
    {
        cout << "Выберите операцию для бинарных отношений: " << endl;
        cout << "1 - объединение, 2 - пересечение, 3 - дополнение, 4 - произведение, 5 - нахождение обратного" << endl;
        int bo_vvod;
        cin >> bo_vvod;

        cout << "Введите размерность : " << endl;
        cin >> N;
        if (N == 0) {
            cout << "Ошибка";
            return 0;
        }
        if (bo_vvod == 1 || bo_vvod == 2 || bo_vvod == 4) {
            cout << "Введите матрицу бинарного отношения №1: " << endl;
            bool** matrix1;
            matrix1 = new bool* [N];
            for (int i = 0; i < N; i++) {
                matrix1[i] = new bool[N];
                for (int j = 0; j < N; j++) {
                    cin >> matrix1[i][j];
                }
            }
            cout << "Введите матрицу бинарного отношения №2: " << endl;
            bool** matrix2;
            matrix2 = new bool* [N];
            for (int i = 0; i < N; i++) {
                matrix2[i] = new bool[N];
                for (int j = 0; j < N; j++) {
                    cin >> matrix2[i][j];
                }
            }

            bin_otn_two(N, matrix1, matrix2, bo_vvod);
        }
        else if (bo_vvod == 3 || bo_vvod == 5) {
            cout << "Введите матрицу бинарного отношения: " << endl;
            bool** matrix;
            matrix = new bool* [N];
            for (int i = 0; i < N; i++) {
                matrix[i] = new bool[N];
                for (int j = 0; j < N; j++) {
                    cin >> matrix[i][j];
                }
            }

            bin_otn_one(N, matrix, bo_vvod);
        }
        else
            cout << "Ошибка" << endl;
    }
    else if (sposob == 3) {
        // требуется рассмотреть операции сложения, умножения, транспонирования и обращения матриц над конечным полем.
        cout << "Выберите операцию для матриц: " << endl;
        cout << "1 - сложение, 2 - умножение, 3 - транспонирование, 4 - обращение" << endl;
        int mat_vvod;
        int N1, M1, N2, M2;
        cin >> mat_vvod;
        int mat_mod;
        cout << "Введите число, по модулю которого будет выполняться операция: " << endl;
        cin >> mat_mod;
        if (mat_vvod == 1 || mat_vvod == 2) {
            cout << "Введите размерность матрицы №1 (N M): " << endl;
            cin >> N1 >> M1;
            cout << "Введите матрицу №1: " << endl;
            int** matrix1;
            matrix1 = new int* [N1];
            for (int i = 0; i < N1; i++) {
                matrix1[i] = new int[M1];
                for (int j = 0; j < M1; j++) {
                    cin >> matrix1[i][j];
                }
            }
            cout << "Введите размерность матрицы №2 (N M): " << endl;
            cin >> N2 >> M2;
            cout << "Введите матрицу №2: " << endl;
            int** matrix2;
            matrix2 = new int* [N2];
            for (int i = 0; i < N2; i++) {
                matrix2[i] = new int[M2];
                for (int j = 0; j < M2; j++) {
                    cin >> matrix2[i][j];
                }
            }

            matr_two(N1, M1, matrix1, N2, M2, matrix2, mat_vvod, mat_mod);
        }
        else if (mat_vvod == 3 || mat_vvod == 4) {
            cout << "Введите размерность матрицы (N M): " << endl;
            cin >> N1 >> M1;
            cout << "Введите матрицу: " << endl;
            int** matrix;
            matrix = new int* [N1];
            for (int i = 0; i < N1; i++) {
                matrix[i] = new int[M1];
                for (int j = 0; j < M1; j++) {
                    cin >> matrix[i][j];
                }
            }

            matr_one(N1, M1, matrix, mat_vvod, mat_mod);
        }
        else
            cout << "Ошибка" << endl;
    }
    else
        cout << "Ошибка" << endl;

    cout << endl;
}
