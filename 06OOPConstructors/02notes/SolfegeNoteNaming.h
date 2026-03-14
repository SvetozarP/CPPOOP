#pragma once
#include "NoteName.h"

#include <string>

class SolfegeNoteNaming {

public:

	NoteName operator()(const std::string& noteText) const;

};