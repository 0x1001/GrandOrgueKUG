/*
 * GrandOrgue - free pipe organ simulator
 *
 * Copyright 2006 Milan Digital Audio LLC
 * Copyright 2009-2013 GrandOrgue contributors (see AUTHORS)
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
 */

#ifndef GORGUESETTINGS_H
#define GORGUESETTINGS_H

#include <wx/wx.h>
#include <map>
#include <vector>
#include "ptrvector.h"
#include "GOrgueOrgan.h"
class wxConfigBase;

typedef struct
{
	wxString name;
	float left;
	float right;
} GOAudioGroupOutputConfig;

typedef struct
{
	wxString name;
	unsigned channels;
	std::vector< std::vector<GOAudioGroupOutputConfig> > scale_factors;
} GOAudioDeviceConfig;

class GOrgueSettings {
private:
	wxConfigBase& m_Config;
	wxString m_InstanceName;
	wxString m_ConfigFileName;
	size_t m_MemoryLimit;
	bool m_Stereo;
	unsigned m_Concurrency;
	unsigned m_ReleaseConcurrency;
	bool m_LosslessCompression;
	bool m_ManagePolyphony;
	bool m_ManageCache;
	bool m_CompressCache;
	bool m_ScaleRelease;
	bool m_RandomizeSpeaking;
	bool m_LoadLastFile;
	unsigned m_SamplesPerBuffer;
	unsigned m_SampleRate;
	unsigned m_BitsPerSample;
	unsigned m_InterpolationType;
	unsigned m_WaveFormat;
	unsigned m_LoopLoad;
	unsigned m_AttackLoad;
	unsigned m_ReleaseLoad;
	int m_Volume;
	unsigned m_PolyphonyLimit;
	unsigned m_Preset;
	ptr_vector<GOrgueOrgan> m_OrganList;
	std::map<wxString, int> m_MidiIn;
	std::map<wxString, bool> m_MidiOut;
	wxString m_WAVPath;
	wxString m_OrganPath;
	wxString m_SettingPath;
	wxString m_UserSettingPath;
	wxString m_UserCachePath;
	wxString m_LastFile;
	std::vector<wxString> m_AudioGroups;
	std::vector<GOAudioDeviceConfig> m_AudioDeviceConfig;
	int m_ManualEvents[6];
	int m_EnclosureEvents[6];
	int m_SetterEvents[3];
	int m_StopChangeEvent;
	int m_Transpose;
	int m_Reverb;
	bool m_ReverbEnabled;
	bool m_ReverbDirect;
	int m_ReverbChannel;
	unsigned m_ReverbStartOffset;
	unsigned m_ReverbLen;
	unsigned m_ReverbDelay;
	float m_ReverbGain;
	wxString m_ReverbFile;

	static const wxString m_ManualNames[];
	static const wxString m_EnclosureNames[];
	static const wxString m_SetterNames[];
	static const wxString m_StopChangeName;

public:
	GOrgueSettings(wxString instance);
	~GOrgueSettings();

	void Load();
	wxConfigBase& GetConfig();
	wxString GetStandardDocumentDirectory();
	wxString GetStandardOrganDirectory();
	wxString GetStandardDataDirectory();
	wxString GetStandardCacheDirectory();

	size_t GetMemoryLimit();
	void SetMemoryLimit(size_t limit);

	unsigned GetManualCount();
	wxString GetManualTitle(unsigned index);
	int GetManualEvent(unsigned index);
	void SetManualEvent(unsigned index, int event);

	unsigned GetEnclosureCount();
	wxString GetEnclosureTitle(unsigned index);
	int GetEnclosureEvent(unsigned index);
	void SetEnclosureEvent(unsigned index, int event);

	unsigned GetSetterCount();
	wxString GetSetterTitle(unsigned index);
	int GetSetterEvent(unsigned index);
	void SetSetterEvent(unsigned index, int event);
	
	wxString GetStopChangeTitle();
	int GetStopChangeEvent();
	void SetStopChangeEvent(int event);

	wxString GetOrganPath();
	void SetOrganPath(wxString path);
	wxString GetSettingPath();
	void SetSettingPath(wxString path);
	wxString GetWAVPath();
	void SetWAVPath(wxString path);

	wxString GetUserSettingPath();
	void SetUserSettingPath(wxString path);
	wxString GetUserCachePath();
	void SetUserCachePath(wxString path);
	wxString GetLastFile();
	void SetLastFile(wxString path);
	unsigned GetPreset();
	void SetPreset(unsigned value);

	bool GetLoadInStereo();
	void SetLoadInStereo(bool stereo);

	unsigned GetConcurrency();
	void SetConcurrency(unsigned concurrency);
	unsigned GetReleaseConcurrency();
	void SetReleaseConcurrency(unsigned concurrency);

	unsigned GetSamplesPerBuffer();
	void SetSamplesPerBuffer(unsigned sampler_per_buffer);

	bool GetLosslessCompression();
	void SetLosslessCompression(bool lossless_compression);
	bool GetManagePolyphony();
	void SetManagePolyphony(bool manage_polyphony);
	bool GetManageCache();
	void SetManageCache(bool manage);
	bool GetCompressCache();
	void SetCompressCache(bool compress);
	bool GetScaleRelease();
	void SetScaleRelease(bool scale_release);
	bool GetRandomizeSpeaking();
	void SetRandomizeSpeaking(bool randomize);
	bool GetLoadLastFile();
	void SetLoadLastFile(bool last_file);
	unsigned GetInterpolationType();
	void SetInterpolationType(unsigned type);
	unsigned GetSampleRate();
	void SetSampleRate(unsigned sample_rate);
	unsigned GetWaveFormatBytesPerSample();
	void SetWaveFormatBytesPerSample(unsigned bytes_per_sample);
	unsigned GetBitsPerSample();
	void SetBitsPerSample(unsigned bits_per_sample);

	unsigned GetLoopLoad();
	void SetLoopLoad(unsigned loop_load);
	unsigned GetAttackLoad();
	void SetAttackLoad(unsigned attack_load);
	unsigned GetReleaseLoad();
	void SetReleaseLoad(unsigned release_load);

	int GetVolume();
	void SetVolume(int volume);
	unsigned GetPolyphonyLimit();
	void SetPolyphonyLimit(unsigned polyphony_limit);

	unsigned GetAudioDeviceLatency(wxString device);
	void SetAudioDeviceLatency(wxString device, unsigned latency);
	int GetAudioDeviceActualLatency(wxString device);
	void SetAudioDeviceActualLatency(wxString device, unsigned latency);

	int GetMidiInDeviceChannelShift(wxString device);
	void SetMidiInDeviceChannelShift(wxString device, int shift);
	std::vector<wxString> GetMidiInDeviceList();

	int GetMidiOutState(wxString device);
	void SetMidiOutState(wxString device, bool enabled);
	std::vector<wxString> GetMidiOutDeviceList();

	const std::vector<wxString>& GetAudioGroups();
	void SetAudioGroups(const std::vector<wxString>& audio_groups);
	unsigned GetAudioGroupId(const wxString& str);
	int GetStrictAudioGroupId(const wxString& str);

	const std::vector<GOAudioDeviceConfig>& GetAudioDeviceConfig();
	void SetAudioDeviceConfig(const std::vector<GOAudioDeviceConfig>& config);

	int GetTranspose();
	void SetTranspose(int transpose);
	int GetReverb();
	void SetReverb(int reverb);

	bool GetReverbEnabled();
	void SetReverbEnabled(bool on);
	bool GetReverbDirect();
	void SetReverbDirect(bool on);
	wxString GetReverbFile();
	void SetReverbFile(wxString file);
	unsigned GetReverbStartOffset();
	void SetReverbStartOffset(unsigned offset);
	unsigned GetReverbLen();
	void SetReverbLen(unsigned length);
	float GetReverbGain();
	void SetReverbGain(float gain);
	int GetReverbChannel();
	void SetReverbChannel(int channel);
	unsigned GetReverbDelay();
	void SetReverbDelay(unsigned delay);

	void AddOrgan(GOrgueOrgan* organ);
	ptr_vector<GOrgueOrgan>& GetOrganList();

	void Flush();
};

#endif
