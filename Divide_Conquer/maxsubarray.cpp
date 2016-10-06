#include<iostream>
#include<vector>
using namespace std;

void max_subarra_test()
{
     vector<int> a = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};

     int lowpos=-1,highpos=-1;
     int sum = find_maximum_subarray(a,0,a.size()-1,&lowpos,&highpos);
     cout <<lowpos<<"   "<<highpos<<endl;
     cout<<sum<<endl;
}


int find_max_corssing_subarray(vector<int>&a, int low, int mid, int high, int *maxleft, int *maxright)
{
    int leftsum = -2147483648;

    int sum = 0;
    //get the maximum sum of the left subarray
    for (int i=mid; i>=low; i--)
    {
        sum = sum+a.at(i);
        if (sum>leftsum)
        {
            leftsum = sum;
            *maxleft = i;
        }
    }

    int rightsum = -2147483648;
    sum = 0;

    //get maximum sum of the right subarray
    for (int i=mid+1;i<=high;i++)
    {
        sum = sum+a[i];
        if (sum>rightsum)
        {
            rightsum = sum;
            *maxright = i;
        }
    }
//    cout<<*maxleft<<"  "<<*maxright<<endl;
//    cout<<leftsum+rightsum<<endl;
    return leftsum+rightsum;
}

int find_maximum_subarray(vector<int>&a, int low, int high, int *low_pos, int *high_pos)
{
    if (low==high)
    {
        *low_pos = low;
        *high_pos = high;
//        cout<< a[low] << endl;
        return a[low];
    }
    else
    {
        int mid = (low+high)/2;
        int leftlow, lefthigh, rightlow, righthigh, crosslow, crosshigh;
        leftlow = -1;
        lefthigh=-1;
        righthigh=-1;
        crosslow=-1;
        crosshigh=-1;
        int leftsum = find_maximum_subarray(a, low, mid, &leftlow, &lefthigh);
        int rightsum = find_maximum_subarray(a, mid+1, high, &rightlow, &righthigh);
        int crosssum = find_max_corssing_subarray(a, low, mid, high, &crosslow, &crosshigh);
        //check which sum is bigger
        if (leftsum>=crosssum && leftsum>=rightsum)
        {
            *low_pos = leftlow;
            *high_pos = lefthigh;
            return leftsum;
        }
        else if (rightsum>=crosssum && rightsum>=leftsum)
        {
            *low_pos = rightlow;
            *high_pos = righthigh;
            return rightsum;
        }
        else
        {
            *low_pos = crosslow;
            *high_pos = crosshigh;
            return crosssum;
        }
    }
}
