#include <cstdio>
#include "classic_algs_exception.h"

namespace classic_algorithms{

    const char *ClassicAlgEx::kDefaultMessagePrefix_ = "Unknown exception";

    ClassicAlgEx::ClassicAlgEx()
        :std::exception(kDefaultMessagePrefix_),
        isLocationKnown(false)
    {
        //int32_t sizeOfMessage = strlen(kDefaultMessagePrefix_);
        //entireMessageSize_ = kMaxAdditionalInfoLength + sizeOfMessage;
        //exceptionMessage_.reset(new char[entireMessageSize_]);
        // strncpy(exceptionMessage_.get(), kDefaultMessagePrefix_, sizeOfMessage);
        //_snprintf(exceptionMessage_.get(), entireMessageSize_, "%s in file %s in function %s at line %u", kDefaultMessagePrefix_, __FILE__, __FUNCTION__, __LINE__);
    }

    ClassicAlgEx::ClassicAlgEx(const std::string& message)
        :std::exception(message.c_str()),
        isLocationKnown(false){
            /*int32_t sizeOfMessage = message.size();
            entireMessageSize_ = sizeOfMessage + kMaxAdditionalInfoLength;
            exceptionMessage_.reset(new char[entireMessageSize_]);
            _snprintf(exceptionMessage_.get(), entireMessageSize_, "%s in file %s in function %s at line %u", message.c_str(), __FILE__, __FUNCTION__, __LINE__);*/
    }

    ClassicAlgEx::ClassicAlgEx( const std::string& message, const std::string& filename, const std::string& functionName, int32_t lineNumber )
        :std::exception(message.c_str())       
    {
        fileName_.reset(new char[filename.size()+1]);
        _snprintf(fileName_.get(), filename.size()+1, "%s", filename.c_str());
        functionName_.reset(new char[functionName.size()+1]);
        _snprintf(functionName_.get(), functionName.size()+1, "%s", functionName.c_str());
        lineNumber_ = lineNumber;      
        isLocationKnown = true;
    }

    ClassicAlgEx::~ClassicAlgEx(){

    }

    const char* ClassicAlgEx::what() const {
        try{
            if(isLocationKnown){
                int32_t entireMessageSize_ = kMaxAdditionalInfoLength + strlen(std::exception::what());
                exceptionMessage_.reset(new char[entireMessageSize_]);
                _snprintf(exceptionMessage_.get(), entireMessageSize_, "%s in file %s in function %s at line %u", std::exception::what(), fileName_.get(), functionName_.get(), lineNumber_);
                return static_cast<const char*>(exceptionMessage_.get());
            }
            else
            {
                return std::exception::what();
            }
        }catch(...){
            return NULL;
        }
    }


    InvalidArgEx::InvalidArgEx()
        :ClassicAlgEx("Exception: invalid argument")
    {

    }

    InvalidArgEx::InvalidArgEx(const std::string& argument)
        :ClassicAlgEx("Exception: invalid argument " + argument)
    {

    }

    InvalidArgEx::InvalidArgEx(const std::string& argument, const std::string& filename, const std::string& functionName, int32_t lineNumber)
        : ClassicAlgEx("Exception: invalid argument " + argument, filename, functionName+"()", lineNumber){

    }
}
