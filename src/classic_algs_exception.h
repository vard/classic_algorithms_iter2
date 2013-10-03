#pragma once

#include <exception>
#include <string>
#include <memory>
#include "boost/shared_array.hpp"

namespace classic_algorithms{

    class ClassicAlgEx : public std::exception{
    public:   
        ClassicAlgEx();
        explicit ClassicAlgEx(const std::string& message);
        ClassicAlgEx(const std::string& message, const std::string& filename, const std::string& functionName, int32_t lineNumber);
        virtual ~ClassicAlgEx();
        virtual const char* what() const;  
    private:
        static const int32_t kMaxAdditionalInfoLength = 400;
        static const char* kDefaultMessagePrefix_;
        bool isLocationKnown;
        int32_t entireMessageSize_;        
        int32_t lineNumber_;
        boost::shared_array<char> fileName_;
        boost::shared_array<char> functionName_;
        mutable boost::shared_array<char> exceptionMessage_;
    };

    class InvalidArgEx : public ClassicAlgEx{
    public: 
        InvalidArgEx();
        explicit InvalidArgEx(const std::string& argument);
        InvalidArgEx(const std::string& argument, const std::string& filename, const std::string& functionName, int32_t lineNumber);
    };
}