/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Copyright (C) 2019, Google Inc.
 *
 * ipa_module.h - Image Processing Algorithm module
 */
#ifndef __LIBCAMERA_IPA_MODULE_H__
#define __LIBCAMERA_IPA_MODULE_H__

#include <stdint.h>
#include <string>
#include <vector>

#include <ipa/ipa_interface.h>
#include <ipa/ipa_module_info.h>

#include "log.h"
#include "pipeline_handler.h"

namespace libcamera {

class IPAModule : public Loggable
{
public:
	explicit IPAModule(const std::string &libPath);
	~IPAModule();

	bool isValid() const;

	const struct IPAModuleInfo &info() const;
	const std::vector<uint8_t> signature() const;
	const std::string &path() const;

	bool load();

	struct ipa_context *createContext();

	bool match(PipelineHandler *pipe,
		   uint32_t minVersion, uint32_t maxVersion) const;

protected:
	std::string logPrefix() const override;

private:
	struct IPAModuleInfo info_;
	std::vector<uint8_t> signature_;

	std::string libPath_;
	bool valid_;
	bool loaded_;

	void *dlHandle_;
	typedef struct ipa_context *(*IPAIntfFactory)(void);
	IPAIntfFactory ipaCreate_;

	int loadIPAModuleInfo();
};

} /* namespace libcamera */

#endif /* __LIBCAMERA_IPA_MODULE_H__ */
