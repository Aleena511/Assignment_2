#include<iostream>
#include <cmath>
using namespace std;

const int QUAD_LEN = 3; // on 2nd thoughts 'quad_len' is stupid in 1 variable, it will always have len = 3, but incase it ever needs to be expanded to multivar
const int NUM_TC = 10;

float get_gt(float quad[][QUAD_LEN], float tp) 
{
    float gt = 0;
    for (int i = QUAD_LEN; i > 0; i--)
        gt += quad[1][QUAD_LEN - i] * pow(tp, i -1);
    return gt;
}

float get_pred(float quad[][QUAD_LEN], float tp)
{
    float pred = 0;
    for (int i = QUAD_LEN; i > 0; i--)
        pred += quad[0][QUAD_LEN - i] * pow(tp, i -1);
    return pred;
}

void run_perceptron(float quad[][QUAD_LEN], float gt_test_point, float lr, int epochs)
{
    float gt = get_gt(quad, gt_test_point);
    float pred = get_pred(quad, gt_test_point);
    int i = 0;
    while (i < epochs)
    {
        if (fabs(gt - pred) < 1e-6)  // we're done
            break;
        
        float error = gt - pred;
        if (!(i % 10))
            cout << "Step " << i << ": prediction = " << pred << ", error = " << error << endl;
        for (int i = 0; i < QUAD_LEN; i++)
            quad[0][i] +=  lr * error * quad[1][i];
        
        i++;
        pred = get_pred(quad, gt_test_point);
    }

    cout << "Final prediction at x=" << gt_test_point << ": " << pred << endl;
    cout << "Target value: " << gt<<endl;
    cout << "Final w = " << quad[0][0] << ", b = " << quad[0][2] << endl;
    
    
    // TEST CASES
    int usr_input = -1;
    for (int i = 0; i < NUM_TC; i++)
    {
        cout << "Please enter int value to test against: ";
        cin >> usr_input;
        gt = get_gt(quad, usr_input);
        pred = get_pred(quad, usr_input);
        cout << "gt: " << gt << endl;
        cout << "pred: " << pred << endl;
        cout << "err: " << gt -pred << endl; // also figure out limiting floating point precision khudi else conv all to double
    }

    //calc accuracy khudi ....
}

int main()
{
    /* 
    simpler (for mathematical purposes) equation of perceptron is:
    pred = sum(const * weight) = x1w1 + x0w0 where w0 = b = bias in this scenario
    so im using an array for all weights, more generic this way
    */ 

   float quad[][QUAD_LEN] = {{0.0, 0.0, 0.0},  // these are your init weights x and bias
                      {2.0, 0.0, -4.0}}; // these are your gts
   // quad to learn = 2x^2 - 4, can be made from above using a loop

   float gt_test_point = 3;
   float learning_rate = 0.01;
   float epochs = 100;
   run_perceptron(quad, gt_test_point, learning_rate, epochs);
}