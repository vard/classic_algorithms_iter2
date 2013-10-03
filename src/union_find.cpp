#include <algorithm>
#include <iomanip>
#include "classic_algs_exception.h"
#include "union_find.h"

namespace classic_algorithms{
    const int quickFindOutTableCellWidth = 3; // QUICK_FIND_OUT_TABLE_CELL_WIDTH 3

    QuickFind::QuickFind( uint32_t itemsCount /*= 0*/ )
    {
        id_.resize(itemsCount);
        uint32_t i = 0;
        std::generate(std::begin(id_), std::end(id_), [&](){
            return (++i)-1;
        } );

    }

    QuickFind::QuickFind(){

    }

    bool QuickFind::connected( uint32_t first, uint32_t second ) const{
        if(first >= id_.size())
            throw InvalidArgEx("first");
        if(second >=id_.size())
            throw InvalidArgEx("second");

        return id_[first] == id_[second];
    }

    void QuickFind::unionElements( uint32_t first, uint32_t second ){
        if(first >= id_.size())
            throw InvalidArgEx("first");
        if(second >=id_.size())
            throw InvalidArgEx("second");

        auto idFirst = id_[first];
        auto idSecond = id_[second];

        std::replace(std::begin(id_),  std::end(id_), idFirst, idSecond);
    }

    uint32_t QuickFind::count() const{
        return id_.size();
    }

    uint32_t QuickFind::find( uint32_t itemIndex ) const{
        if(itemIndex >= id_.size())
            throw InvalidArgEx("itemIndex");
        return id_[itemIndex];
        return 0;
    }

    UnionFindInterface::~UnionFindInterface(){

    }

    std::ostream& operator<<(std::ostream& out, const UnionFindInterface& rhs){
        uint32_t i = 0;

        out << std::setw(10) << "parent ";
        for(auto j : rhs.id_){
            out << std::setw(quickFindOutTableCellWidth) << i++ << "  ";
        } 
        out << std::endl;
        out << std::setw(10) << "id ";
        for(auto item : rhs.id_){
            out << std::setw(quickFindOutTableCellWidth) << item << "  ";;
        } 
        out << std::endl;
        return out;
    }

    uint32_t QuickUnion::find(uint32_t itemIndex) const{
        if(itemIndex >= id_.size())
            throw InvalidArgEx("itemIndex");

        uint32_t root = itemIndex;
        while(id_[root]!=root)
            root = id_[root];
        return root;
    }

    QuickUnion::QuickUnion(){

    }

    QuickUnion::QuickUnion( uint32_t itemsCount ){
        id_.resize(itemsCount); // if reallocation occurs exception could happen
        auto n = 0;
        std::generate(std::begin(id_), std::end(id_), [&]{
            return n++;
        });
    }

    uint32_t QuickUnion::count() const{
        return id_.size();
    }

    void QuickUnion::unionElements( uint32_t first, uint32_t second ){
        if(first >= id_.size())
            throw InvalidArgEx("first");
        if(second >= id_.size())
            throw InvalidArgEx("second");

        auto firstRoot = find(first);
        id_[firstRoot] = second;
    }

    bool QuickUnion::connected( uint32_t first, uint32_t second ) const{
        if(first >= id_.size())
            throw InvalidArgEx("first");
        if(second >= id_.size())
            throw InvalidArgEx("second");

        return find(first) == find(second);
    }



    WeightedQuickUnion::WeightedQuickUnion(){

    }

    WeightedQuickUnion::WeightedQuickUnion( uint32_t itemsCount ){
        id_.resize(itemsCount);
        uint32_t n = 0;
        std::generate(std::begin(id_), std::end(id_), [&](){
            return n++;
        });
        rank_.resize(itemsCount, 0);
    }

    bool WeightedQuickUnion::connected( uint32_t first, uint32_t second ) const{
        if(first >= id_.size())
            throw InvalidArgEx("first");
        if(second >= id_.size())
            throw InvalidArgEx("second");

        return find(first) == find(second);
    }

    uint32_t WeightedQuickUnion::count() const{
        return id_.size();
    }

    void WeightedQuickUnion::unionElements( uint32_t first, uint32_t second ){
        if(first >= id_.size())
            throw InvalidArgEx("first");
        if(second >= id_.size())
            throw InvalidArgEx("second");

        auto rootA = find(first);
        auto rootB = find(second);

        if(rank_[rootA] > rank_[rootB]){
            id_[rootB] = rootA;
        } else if(rank_[rootA] < rank_[rootB]){
            id_[rootA] = rootB;
        } else { // equal
            id_[rootA] = rootB;
            ++rank_[rootB];
        }
    }

    uint32_t WeightedQuickUnion::find( uint32_t itemIndex ) const{
        if(itemIndex >= id_.size())
            throw InvalidArgEx("itemIndex");
        auto parent = itemIndex;
        while(id_[parent] != parent)
            parent = id_[parent];

        return parent;
    }


    uint32_t WeightedQuickUnionPC::find( uint32_t itemIndex ) const{
        if(itemIndex >= id_.size())
            throw InvalidArgEx("itemIndex");
        auto parent = itemIndex;
        while(id_[parent] != parent){
            
            id_[parent] = id_[id_[parent]];
            parent = id_[parent];
        }

        return parent;
    }

    WeightedQuickUnionPC::WeightedQuickUnionPC(){

    }

    WeightedQuickUnionPC::WeightedQuickUnionPC( uint32_t itemsCount )
        :WeightedQuickUnion(itemsCount){

    }

};