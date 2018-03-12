// Copyright (c) 2012-2018, The CryptoNote developers, The Vuecash developers.
// Licensed under the GNU Lesser General Public License. See LICENSING.md for details.

#include "MiningConfig.hpp"
#include "common/CommandLine.hpp"
#include "common/Ipv4Address.hpp"

#include <iostream>
#include <thread>

#include "CryptoNoteConfig.hpp"
#include "logging/ILogger.hpp"

using namespace vuecash;

MiningConfig::MiningConfig(common::CommandLine &cmd)
    : vuecashd_ip("127.0.0.1"), vuecashd_port(RPC_DEFAULT_PORT), thread_count(std::thread::hardware_concurrency()) {
	if (const char *pa = cmd.get("--address"))
		mining_address = pa;
	if (const char *pa = cmd.get("--vuecashd-address")) {
		if (!common::parse_ip_address_and_port(vuecashd_ip, vuecashd_port, pa))
			throw std::runtime_error("Wrong address format " + std::string(pa) + ", should be ip:port");
	}
	if (const char *pa = cmd.get("--daemon-address", "Use --vuecashd-address instead")) {
		if (!common::parse_ip_address_and_port(vuecashd_ip, vuecashd_port, pa))
			throw std::runtime_error("Wrong address format " + std::string(pa) + ", should be ip:port");
	}
	if (const char *pa = cmd.get("--daemon-host", "Use --vuecashd-address instead"))
		vuecashd_ip = pa;
	if (const char *pa = cmd.get("--daemon-rpc-port", "Use --vuecashd-address instead"))
		vuecashd_port = boost::lexical_cast<uint16_t>(pa);
	if (const char *pa = cmd.get("--threads"))
		thread_count = boost::lexical_cast<size_t>(pa);
	if (const char *pa = cmd.get("--limit"))
		blocks_limit = boost::lexical_cast<size_t>(pa);
}
