#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

struct PossibleValue {bool flag; int value;};

int main() {
    std::vector numbers = {1,26,7,10,21,32};
    std::sort(begin(numbers),end(numbers));
    numbers.push_back(-1);
    numbers.push_back(-4);
    std::ranges::sort(numbers); // passing whole thing

    std::vector <int> evens;
    std::ranges::copy_if(numbers,std::back_inserter(evens),[](int n) { return n %2 ==0;});
    std::vector <int> rEvens;
    std::copy_if(numbers.begin(), numbers.end(),std::back_inserter(rEvens),[](int n) { return n %2 ==0;});

    auto vEvens = numbers | std::views::filter([](int n){return n%2==0;}); //  | <- nałożenie widoku
    std::vector<PossibleValue> values = {{true,1},{true,2},{false,3},{true,4},{false,5}};
    auto flagged = [](PossibleValue pv){return pv.flag;};

    auto members = values
            | std::views::filter(flagged)
            | std::views::transform([](PossibleValue pv){return pv.value;});
    for ( auto i:members){
        std::cout<<i<<"\n";
    }
    return 0;
}
