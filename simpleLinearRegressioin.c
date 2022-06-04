// Simple Linear Regression Problem In C
#include <time.h>  //For Time
#include <stdio.h> // Import For Input Output

// Function To Calculate Mean Of An Array
float calculateMean(float *num, int length)
{
  float sum = 0.0;

  for (int i = 0; i < length; ++i)
  {
    sum = num[i] + sum;
  }

  return sum / length;
}

// Funciton to return value of slope and intercept inputs are X_train , y_train ,Length Of Array And Dummy Array For Parameters

float *fit(float *X_train, float *y_train, int length, float *paramsArray)
{
  float num = 0.0;
  float den = 0.0;
  float X_train_mean = calculateMean(X_train, length);
  float y_train_mean = calculateMean(y_train, length);

  for (int i = 0; i < length; i++)
  {

    num += (X_train[i] - X_train_mean) * (y_train[i] - y_train_mean);
    den += (X_train[i] - X_train_mean) * (X_train[i] - X_train_mean);
  }
  // Formula For m (Slope) is ((X-X_mean)*(y-y_mean))/(X-X_mean)*(X-X_mean)
  //  Formula For b (Intercept) is y_mean-(m*X_mean)
  float m = num / den;
  float b = y_train_mean - (m * X_train_mean);

  paramsArray[0] = m;
  paramsArray[1] = b;
  return paramsArray;
}
float *predict(float *test, float m, float b, float *pred, int length,int prediction)
{
  // Formula For The Prediction Is y = mx+b
  //  Here y is prediction value,m is slope value ,x is value on x axis,b is intercept value
  for (int i = 0; i < length; i++)
  { 
    if (prediction == 0)
    {
    pred[i] = m * test[i] + b;
      
    }
    else
    {
      pred[i] = (test[i]-b)/m;
    }
    
    
  }
  return pred;
}

int main()
{
  float X_train[10] = {1.4, 2.2, 3.1, 4.7, 5.3, 6.8, 7.2, 8.8, 9.3, 10.7};
  float y_train[10] = {18, 28, 38, 57, 58, 67, 78, 92, 109, 126};
  int pred_len;
  printf("To Predict Salary With Exprience Type '0' Or For Inverse Type '1' :\n");
  int inverse ;
  scanf("%d", &inverse);
  
  printf("How Much Values You Want To Test : ");
  scanf("%d", &pred_len);
  float test[pred_len];
  for (int i = 0; i < pred_len; i++)
  {
    float temp_num;
    printf("No.%d) Enter Exprience In Year.Month Or Salary In Thousand For Prediction : ", i);
    scanf("%f", &temp_num);
    test[i]= temp_num;

  }

  float pred_temp[pred_len];
  float paramsArray[2];
  // Decaring Variable For Time Calculation
  clock_t start, end;
  double cpu_time_used;
  start = clock();
  float *params = fit(X_train, y_train, 10, paramsArray);
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  float m = params[0];
  float b = params[1];

  float *pred = predict(test, m, b, pred_temp, pred_len,inverse);
  for (int i = 0; i < pred_len; i++)
  {
    if (inverse==0)
    {
    printf("\n Salary For %f Year Exprience Is  %f Thousand", test[i], pred[i]);
    }
    else
    {
    printf("\n Exprience Must Be %f Years For %f Thousand Salary", pred[i],test[i]); 
    }
  }
  printf("\n Time Taken For Training Data is %f", cpu_time_used);
}
