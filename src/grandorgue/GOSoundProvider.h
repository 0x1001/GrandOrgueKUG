/*
 * GrandOrgue - free pipe organ simulator
 *
 * Copyright 2006 Milan Digital Audio LLC
 * Copyright 2009-2012 GrandOrgue contributors (see AUTHORS)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * MA 02111-1307, USA.
 */

#ifndef GOSOUNDPROVIDER_H_
#define GOSOUNDPROVIDER_H_

#include <vector>
#include "GOSoundAudioSection.h"
#include "ptrvector.h"
class GOrgueMemoryPool;
class GOrgueCache;
class GOrgueCacheWriter;

typedef struct audio_section_stream_s audio_section_stream;

typedef struct
{
} attack_section_info;

typedef struct
{
} release_section_info;

class GOSoundProvider
{

protected:
 	unsigned m_MidiKeyNumber;
	float m_MidiPitchFract;
	float             m_Gain;
	float             m_Tuning;
	ptr_vector<GOAudioSection> m_Attack;
	std::vector<attack_section_info> m_AttackInfo;
	ptr_vector<GOAudioSection> m_Release;
	std::vector<release_section_info> m_ReleaseInfo;
	GOrgueMemoryPool &m_pool;
	void ComputeReleaseAlignmentInfo();

public:
	GOSoundProvider(GOrgueMemoryPool& pool);
	virtual ~GOSoundProvider();

	void ClearData();

	virtual bool LoadCache(GOrgueCache& cache);
	virtual bool SaveCache(GOrgueCacheWriter& cache);

	const GOAudioSection* GetRelease(const audio_section_stream* handle, double playback_time) const;
	const GOAudioSection* GetAttack() const;
	float GetGain() const;
	int IsOneshot() const;

	float GetTuning() const;
	void SetTuning(float cent);

	unsigned GetMidiKeyNumber() const;
	float GetMidiPitchFract() const;
};

inline
float GOSoundProvider::GetGain() const
{
	return m_Gain;
}

inline
float GOSoundProvider::GetTuning() const
{
	return m_Tuning;
}

#endif /* GOSOUNDPROVIDER_H_ */
