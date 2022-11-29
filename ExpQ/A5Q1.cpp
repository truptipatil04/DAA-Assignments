#include<bits/stdc++.h>
using namespace std;

// vector<pair<int,int>> points;
pair<int,int>  p0;

// function to get next point of top of stack
pair<int,int> nexttoTop(stack<pair<int,int>>& s){
    pair<int,int> pr=s.top();
    s.pop();
    pair<int,int> nxt=s.top();
    s.push(pr);
    return nxt;
}

// function to calculate distance
int distanceSqr(pair<int,int> p1,pair<int,int> p2){
    return (p1.first - p2.first)*(p1.first - p2.first)+
           (p1.second - p2.second)*(p1.second - p2.second);
}

/*  0 = x, y, z are collinear
    1 = clockwise
    2 = counterclockwise
*/
int orientation(pair<int,int> x,pair<int,int> y,pair<int,int> z){
    int val=(y.second - x.second)*(z.first - y.first)-
            (y.first - x.first)*(z.second - y.second);

    if(val == 0){
        return 0; //collinear
    }

    return (val > 0) ? 1 : 2; //clockwise counterclockwise
}

// function to sort the points
int compare(const void *a,const void *b){
    pair<int,int>* pa = (pair<int,int>*) a;
    pair<int,int>* pb = (pair<int,int>*) b;

    int o = orientation(p0,*pa,*pb);

    if(o == 0){
        return ((distanceSqr(p0,*pb) >= distanceSqr(p0,*pa)) ? -1 : 1);
    }
    return (o == 2) ? -1 : 1;
}

int main(){
    vector<pair<int,int>> points = {{1,4},{4,4},{7,4},{1,3},{3,3},{6,3},{8,3},{1,2},
                                   {3,2},{5,2},{7,2},{9,2},{2,1},{4,1},{6,1},{8,1}};
    int n=points.size();

    // Finding bottom most point
    int ymin=points[0].second,min=0;
    for(int i=0;i<points.size();i++){
        int y=points[i].second;

        if((y < ymin) || (y == ymin && points[i].first < points[min].first)){
            ymin = points[i].second;
            min = i;
        }
    }

    // Swap bottom point with first point in set
    swap(points[0],points[min]);

    /* Sort the points according to polar angle w.r.t first/bottom point and 
     keep farthest point at end if points have same orientation */
    p0 = points[0];

    qsort(&points[1],n-1,sizeof(pair<int,int>),compare);

    /*If 2 or more points are collinear than remove all the points except the furthest point 
    from the bottom-most point */ 
    int m=1;
    for(int i=0;i<n;i++){
        while(i<n-1 &&  orientation(p0,points[i],points[i+1])==0){
            i++; 
        }

        points[m++]=points[i];
    }

    // if size is less than 3 then convex polygon is not possible
    if(m<3){
        cout<<"Solution not possible"<<endl;
        return -1;
    }
    
    // maintain a stack to store points
    stack<pair<int,int>> s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);

    /* remove the point from the stack if polar angle formed by it is not on left turn
       else push it in stack */
    for(int i=3;i<m;i++){
        while(s.size()>1 && orientation(nexttoTop(s),s.top(),points[i])!=2){
            s.pop();
        }
        s.push(points[i]);
    }

    // Print the points of convex hull
    while(!s.empty()){
        pair<int,int> pt=s.top();
        cout<<"("<<s.top().first<<", "<<s.top().second<<")"<<endl;
        s.pop();
    }
    
    return 0;
}