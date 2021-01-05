#ifndef COMMAND_CAT_HPP
#define COMMAND_CAT_HPP

/*

Osmium -- OpenStreetMap data manipulation command line tool
https://osmcode.org/osmium-tool/

Copyright (C) 2013-2021  Jochen Topf <jochen@topf.org>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#include "cmd.hpp" // IWYU pragma: export

#include <osmium/io/reader.hpp>
#include <osmium/io/writer.hpp>
#include <osmium/util/progress_bar.hpp>

#include <string>
#include <vector>

class CommandCat : public Command, public with_multiple_osm_inputs, public with_osm_output {

    enum clean_options : uint8_t {
        clean_version   = 0x01,
        clean_changeset = 0x02,
        clean_timestamp = 0x04,
        clean_uid       = 0x08,
        clean_user      = 0x10
    };

    uint8_t m_clean_attrs = 0;

    void copy(osmium::ProgressBar& progress_bar, osmium::io::Reader& reader, osmium::io::Writer &writer) const;

public:

    explicit CommandCat(const CommandFactory& command_factory) :
        Command(command_factory) {
    }

    bool setup(const std::vector<std::string>& arguments) override final;

    void show_arguments() override final;

    bool run() override final;

    const char* name() const noexcept override final {
        return "cat";
    }

    const char* synopsis() const noexcept override final {
        return "osmium cat [OPTIONS] OSM-FILE...";
    }

}; // class CommandCat


#endif // COMMAND_CAT_HPP
