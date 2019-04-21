/*-----------------------------------------------------------------------------

                                                        Author: Nate Browne
                                                        Date: 20 Aug 2018
                        AVL Tree Implementation

File Name:       driver.h
Description:     This file sets up the sample UCSDStudent class for use in the
                 avl_tree's driver. Any primitive/class can be used if it
                 overloads the == operator, adds a get_name (for classes), and
                 overloads the > operator
-----------------------------------------------------------------------------*/
#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>
#include <cstdlib>

/*===========================================================================
/  class USCDStudent
/
/  Description: Implements the UCSDStudent class.
/
/  Data Fields:
/     std::string name: student's name
/     int studentnum: student's number
/
/  Public Functions:
/     UCSDStudent(const std::string & name, int sn): constructor that takes in a
/                                      name and number
/     const std::string get_name(): returns the name of the student
/     operator > (const UCSDStudent & stu): overloads > to do alphabetized
/                                           string comp
/     operator == (const UCSDStudent & stu): overloads == to do string
/                                            comparison
/==========================================================================*/
class UCSDStudent {

  // private fields
  friend std::ostream & operator << (std::ostream &, const UCSDStudent &);
  std::string name;
  int studentnum;

public:

/*-----------------------------------------------------------------------------
% Routine Name: UCSDStudent(std::string name, int sn)
% File: driver.h
%
% Description:  two-arg constructor for the student. Second arg is optional and
% has a default value of 0;
%
% Result:       A UCSDStudent is created
% Return:       N/A
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% name              Name of the student
# studentnum        Student number of the student
-----------------------------------------------------------------------------*/
  UCSDStudent(const std::string & name, int snm = 0) : studentnum(snm) {

    this->name = name;
  }

/*-----------------------------------------------------------------------------
% Routine Name: ~UCSDStudent(void)
% File: driver.h
%
% Description:  Deletes a student
%
% Result:       Student is deleted
% Return:       N/A
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% N/A
-----------------------------------------------------------------------------*/
  ~UCSDStudent(void) { }

/*-----------------------------------------------------------------------------
% Routine Name: operator ==
% File: driver.h
%
% Description:  Overrides object equality for name comparison
%
% Result:       The names are compared
% Return:       true if the names are the same, false otherwise
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% stu               reference to another UCSDStudent object
-----------------------------------------------------------------------------*/
  bool operator == (const UCSDStudent & stu) const {

    return this->name == stu.name;
  }

/*-----------------------------------------------------------------------------
% Routine Name: operator >
% File: driver.h
%
% Description:  Does name comparison to determine "larger" name
%
% Result:       names are compared
% Return:       true if the calling object's name is "larger", false otherwise
% Parameters descriptions:
%
% name              description
------------------ ------------------------------------------------------
% stu               reference to another UCSDStudent object
-----------------------------------------------------------------------------*/
  bool operator > (const UCSDStudent & stu) const {

    return this->name > stu.name;
  }
};

std::ostream & operator << (std::ostream & stream, const UCSDStudent & stu) {
  return stream << "name: " << stu.name << " with student number: " << stu.studentnum;
}

#endif
