#ifndef CURRICULUM_H
#define CURRICULUM_H

#include <vector>
#include <memory>
#include "Course.h"

class Curriculum {
    private:
        std::vector<std::unique_ptr<Course>> _available_courses;
    public:
        Curriculum();

        void print_courses();

        const Course* request(std::string id) const;
};

#endif // CURRICULUM_H