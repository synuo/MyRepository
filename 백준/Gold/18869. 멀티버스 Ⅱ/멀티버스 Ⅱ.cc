#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//좌표 압축 함수
vector<int> comp(vector<int>& v){
    vector<int> copy(v);   //벡터 v 복사하여 벡터 copy에 저장
    sort(copy.begin(), copy.end());  //벡터 copy 정렬
    copy.erase(unique(copy.begin(), copy.end()), copy.end()); //중복 원소 제거
    vector<int> result(v.size()); //좌표 압축 저장할 벡터 result(크기는 벡터 v와 동일)
    for(int i=0;i<v.size();i++){
        result[i] = lower_bound(copy.begin(), copy.end(), v[i]) - copy.begin();
    }
    //정렬된 배열에서 값보다 크거나 같은 첫번째 원소의 위치를 반환 후
    //copy.begin()으로 빼서 v[i]가 배열에서 몇번째 위치에 있는지 계산

    return result;   //좌표 압축 결과 반환
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M,N;
    cin>>M>>N; //우주 개수, 우주의 행성 개수

    vector<vector<int>> u(M);  //각 우주 좌표를 입력할 2차원 벡터 u

    for(int i=0;i<M;i++){
        vector<int> v(N);
        for(int j=0;j<N;j++){
            cin>>v[j];
        }
        u[i] = comp(v); //좌표 압축
    }
    
    //우주 쌍이 균등한지 비교
    int cnt=0;
    for(int i=0;i<M-1;i++){
        for(int j=i+1;j<M;j++){
            //좌표 압축 결과 벡터의 크기 동일, 값 동일 시 cnt 증가
            if(u[i].size() == u[j].size() && u[i] == u[j]){
                cnt++;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}