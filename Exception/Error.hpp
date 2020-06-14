/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

class Error : public std::exception {
    public:
        Error(const std::string &msg);
        virtual ~Error() throw() {}
        virtual const char *what() const throw();
    protected:
        std::string _error_msg;
};

class StorageError : public Error
{
    public:
        StorageError(const std::string &msg);
        virtual ~StorageError() throw(){}
};

class ButtonError : public Error
{
    public:
        ButtonError(const std::string &msg);
        virtual ~ButtonError() throw(){}
};

class MusicError : public Error
{
public:
    MusicError(const std::string &msg);
    virtual ~MusicError() throw(){}
};

class SoundError : public Error
{
public:
    SoundError(const std::string &msg);
    virtual ~SoundError() throw(){}
};


#endif /* !EXCEPTION_HPP_ */
