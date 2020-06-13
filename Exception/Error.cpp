/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(const std::string &msg = "")
{
    _error_msg = msg;
}

const char *Error::what() const throw()
{
    return _error_msg.c_str();
}

StorageError::StorageError(const std::string &msg = "") : Error(msg)
{

}