// NumericalAnalysis.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;
double Function(double Xt,double a,double b,double input)
{
    static double dXt = 0;
    dXt = a * Xt + b * input;
    return dXt;
}

void Euler(double&Xt1,double&Xt,double&dXt,double dt,double input,double _a,double _b)
{
    dXt = _a * Xt + _b * input;
    Xt+= dt * dXt;
}

void Euler( double& Xt ,double dt, double input, double _a, double _b)
{
    double dXt = _a*Xt + _b * input;
    Xt += dt * dXt;
}


void ModifiedEuler(double& Xt,double dt, double input, double _a, double _b)
{
   double  dXt = _a * Xt + _b * input;
   double  pXt1 = Xt + dt * dXt;
    double pdXt1 = _a * pXt1 + _b * input;
    Xt += 0.5 * dt * (dXt + pdXt1);
}


void RungeKutta4(double& Xt, double dt, double input, double a, double b)
{
    double k1 = a * Xt + b * input;
    double k2 = a * (Xt + k1 / 2) + b * input;
    double k3 = a * (Xt + k2 / 2) + b * input;
    double k4 = a * (Xt + k3) + b * input;
    Xt += dt * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
}



int main()
{
    double a = 0.001;
    double b = 0.003;
    double dt = 1.0;
    double input = 0;
    double input0 = 3;
    double input1 = 3;
    double input2 = 3;
    double input3 = 3;
    double aX1 = 0;
    double aX = 0;
    double adX = 0;
    double bX1 = 0;
    double bX = 0;
    double cX = 0;

    int i = 0;

    while (1) {
        RungeKutta4(aX, dt, input, a, b);
        Euler(bX, dt, input, a, b);
        ModifiedEuler(cX, dt, input, a, b);
        cout << i << " , "<<input<<" , " << aX << " , " << bX << " , " << cX << endl;
        i++;
        if (i > 0)
        {
            input = input0;;
                if (i > 100)
                {
                    input = input1;
                    if (i > 200)
                    {
                        input = input2;
                        if (i > 300)
                        {
                            input = input3;
                            if (i == 400)
                            {
                                break;
                            }
                        }
                    }
                }
        }
    
    }

}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
