#pragma once

#include <cstdint>
#include <vector>
#include <ostream>
#include "boost/utility.hpp"

namespace classic_algorithms{

    class UnionFindInterface : boost::noncopyable{
    public:
        virtual bool connected(uint32_t first, uint32_t second) const  = 0;
        virtual void unionElements(uint32_t first, uint32_t second) = 0;
        virtual uint32_t count() const = 0;
        virtual uint32_t find(uint32_t itemIndex) const = 0;
        virtual ~UnionFindInterface();
        friend std::ostream& operator<<(std::ostream& out, const UnionFindInterface& rhs);
    protected:
        mutable std::vector<uint32_t> id_;    
    };

    class QuickFind : public UnionFindInterface{
    public:
        QuickFind();
        explicit QuickFind(uint32_t itemsCount);
        virtual bool connected(uint32_t first, uint32_t second) const;
        virtual void unionElements(uint32_t first, uint32_t second);
        virtual uint32_t count() const;
        virtual uint32_t find(uint32_t itemIndex) const;
    };

    class QuickUnion : public UnionFindInterface{
    public:
        QuickUnion();
        explicit QuickUnion(uint32_t itemsCount);
        virtual bool connected(uint32_t first, uint32_t second) const;
        virtual void unionElements(uint32_t first, uint32_t second);
        virtual uint32_t count() const;
        virtual uint32_t find(uint32_t itemIndex) const;
    };

    class WeightedQuickUnion : public UnionFindInterface{
    public:
        WeightedQuickUnion();
        explicit WeightedQuickUnion(uint32_t itemsCount);
        virtual bool connected(uint32_t first, uint32_t second) const;
        virtual void unionElements(uint32_t first, uint32_t second);
        virtual uint32_t count() const;
        virtual uint32_t find(uint32_t itemIndex) const;
    protected:
        std::vector<int32_t> rank_;
    };

    class WeightedQuickUnionPC : public WeightedQuickUnion {  // weighted quick-union with path compression
    public:
        WeightedQuickUnionPC();
        explicit WeightedQuickUnionPC(uint32_t itemsCount);
        virtual uint32_t find(uint32_t itemIndex) const;
    };


}