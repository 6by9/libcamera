/* SPDX-License-Identifier: BSD-2-Clause */
/*
 * Copyright (C) 2021, Raspberry Pi Ltd
 *
 * cam_helper_Ar0234.cpp - camera information for Ar0234 sensor
 */

#include <assert.h>

#include "cam_helper.h"

using namespace RPiController;

class CamHelperAr0234 : public CamHelper
{
public:
	CamHelperAr0234();
	uint32_t gainCode(double gain) const override;
	double gain(uint32_t gainCode) const override;

private:
	/*
	 * Smallest difference between the frame length and integration time,
	 * in units of lines.
	 */
	static constexpr int frameIntegrationDiff = 4;
};

/*
 * Ar0234 doesn't output metadata, so we have to use the "unicam parser" which
 * works by counting frames.
 */

CamHelperAr0234::CamHelperAr0234()
	: CamHelper({}, frameIntegrationDiff)
{
}

uint32_t CamHelperAr0234::gainCode(double gain) const
{
	return static_cast<uint32_t>(gain * 16.0);
}

double CamHelperAr0234::gain(uint32_t gainCode) const
{
	return static_cast<double>(gainCode) / 16.0;
}

static CamHelper *create()
{
	return new CamHelperAr0234();
}

static RegisterCamHelper reg("ar0234", &create);
