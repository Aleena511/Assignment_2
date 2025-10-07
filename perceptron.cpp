#include <iostream>
#include <cmath>
using namespace std;

int main() { //basic format
    

    // part a


    // set variables
    double w = 0.0;         
    double b = 0.0;          
    double learningrate = 0.01;
    int epochs = 1000;


    //more variables 
    double x_train = 3.0;                      
    double target = 2 * pow(x_train, 2) - 4;    // f(x) = 2x² - 4 = 14

    cout << "TRAINING PHASE <3 \n";
    for (int i = 0; i < epochs; i++) {
        double y = w * x_train + b;     
        double error = target - y;   

        //make equations
        w = w + learningrate * error * x_train;
        b = b + learningrate * error;

        // print progress every 100 steps
        if (i % 100 == 0)
            cout << "Step " << i << ": prediction = " << y << ", error = " << error << endl;
    }
//OUTPUT 
    double finalprediction = w * x_train + b;
    cout << "\nFinal prediction at x=" << x_train << ": " << finalprediction << endl;
    cout << "Target value: " << target << endl;
    cout << "Final w = " << w << ", b = " << b << endl;


    // Part b
    cout << "\n TESTING PHASE <3\n";
    int correctCount = 0;
    int totalTests = 10;

    // user input 
    for (int i = 0; i < totalTests; i++) {
        double x;
        cout << "\nEnter x" << i + 1 << ": ";
        cin >> x;

        // prediction
        double prediction = w * x + b;
        double trueValue = 2 * pow(x, 2) - 4;
        double diff = fabs(prediction - trueValue);

        cout << "x = " << x 
             << ", prediction = " << prediction 
             << ", target = " << trueValue;

        if (diff <= 1.0) {
            cout << " -> correct ";
            correctCount++;
        } else {
            cout << " -> incorrect ";
        }
        cout << endl;
    }
// test for accuracy
    double accuracy = (double(correctCount) / totalTests) * 100.0;
    cout << "\nOverall Accuracy: " << accuracy << "%" << endl;

    return 0;
}
