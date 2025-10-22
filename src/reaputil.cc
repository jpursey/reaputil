// Copyright (c) 2025 John Pursey
//
// Use of this source code is governed by an MIT-style License that can be found
// in the LICENSE file or at https://opensource.org/licenses/MIT.

#include <iostream>
#include <string_view>
#include <vector>

#include "absl/types/span.h"
#include "gb/base/context_builder.h"
#include "gb/file/file_system.h"
#include "gb/file/local_file_protocol.h"
#include "src/clean_project.h"

namespace rpu {

bool Main(absl::Span<const std::string_view> args) {
  if (args.size() != 1) {
    std::cerr << "Usage: reaputil <command> <args...>" << std::endl;
    return false;
  }

  gb::FileSystem file_system;
  file_system.Register(gb::LocalFileProtocol::Create(
      gb::ContextBuilder().SetValue<std::string>("root", "/").Build()));
  file_system.SetDefaultProtocol("file");

  if (args[0] == "clean") {
  	CleanProject(file_system);
  } else {
  	std::cerr << "Unknown command: " << args[0] << std::endl;
  }

  return true;
}

}  // namespace rpu

int main(int argc, const char* argv[]) {
  std::vector<std::string_view> args(argc - 1);
  for (int i = 1; i < argc; ++i) {
    args[i - 1] = argv[i];
  }
  return rpu::Main(args) ? 0 : -1;
}