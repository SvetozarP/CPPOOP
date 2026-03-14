#include "SolfegeNoteNaming.h"

#include <string>

NoteName SolfegeNoteNaming::operator()(const std::string& noteText) const {
	if (noteText == "Do") return NoteName('C');
	if (noteText == "Re") return NoteName('D');
	if (noteText == "Mi") return NoteName('E');
	if (noteText == "Fa") return NoteName('F');
	if (noteText == "Sol") return NoteName('G');
	if (noteText == "La") return NoteName('A');
	if (noteText == "Si") return NoteName('B');
	else return NoteName('?');
}



