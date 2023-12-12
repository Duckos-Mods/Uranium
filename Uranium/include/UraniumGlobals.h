#pragma once
#include <Utils/RandomTypes.h>
#include <SimdJson/simdjson.h>
#include <UUID_V4/UUID_V4.h>
namespace Uranium
{
	static FormatVersion GlobalFormatVersion = FormatVersion(1, 20, 40);
	static simdjson::dom::parser GlobalParser;
	static std::string GlobalProjectNamespace;
	static UUIDv4::UUIDGenerator<std::mt19937_64> GlobalUUIDGenerator;
}