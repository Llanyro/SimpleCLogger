#include "llanysimpleprint.hpp"
#include "logger.hpp"


int main(int argc, char** argv) {
	llcpp::logger::Logger* l = new llcpp::logger::Logger(".//logs");
	l->custom_log("test.txt", "%s %i", "Hola mundo!", 19212);
	l->custom_log("test.txt", "%s %i", "Hola mundo!", 19212);

	l->log("%s %i %s", "Logging something", 19212, "Patata");
	l->log("%s %i %s", "Logging something", 19212, "Patata");

	l->error("%s %s %s", "Error!!!", "NOOB", "AHJDNF");
	l->error("%s %s %s", "Error!!!", "NOOB", "AHJDNF");

	l->info("%s %s", "This is a warning", "AHJDNF");
	l->info("%s %s", "This is a warning", "AHJDNF");

	delete l;

	return 0;
}