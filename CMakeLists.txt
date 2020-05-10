cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(krkrv)
include("${VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "Kirikiri for Playstation Vita")
set(VITA_TITLEID  "KRKR00001")
set(VITA_VERSION  "01.00")


set(EXFLAGS  "-DTVP_COMPRESSION_ENABLE_ZLIB -DTVP_IMAGE_ENABLE_BMP -DTVP_IMAGE_ENABLE_TLG -DTVP_IMAGE_ENABLE_PNG -DTVP_IMAGE_ENABLE_JPEG -DTVP_AUDIO_ENABLE_WAVE -DTVP_AUDIO_ENABLE_VORBIS -DTVP_ARCHIVE_ENABLE_XP3 -DTVP_TEXT_READ_ANSI_MBCS")


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${EXFLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EXFLAGS} -fno-delete-null-pointer-checks -fpermissive")

include_directories(
  source source/core source/core/movie source/core/movie/ffmpeg source/core/extension source/core/msg source/core/msg/win32 source/core/tjs2 source/core/utils source/core/utils/encoding source/core/utils/win32 source/core/environ source/core/environ/android source/core/environ/win32 source/core/visual source/core/visual/gl source/core/visual/win32 source/core/sdl2 source/core/sound source/core/sound/win32 source/core/base source/core/base/android source/core/base/win32 source/plugins source/plugins/ncbind
)

include_directories($ENV{VITASDK}/arm-vita-eabi/include/freetype2)

add_executable(${PROJECT_NAME}
  source/core/movie/krmovie.cpp
  source/core/extension/Extension.cpp
  source/core/msg/MsgIntf.cpp
  source/core/msg/win32/MsgImpl.cpp
  source/core/tjs2/tjsDebug.cpp
  source/core/tjs2/tjsScriptBlock.cpp
  source/core/tjs2/tjsConstArrayData.cpp
  source/core/tjs2/tjsCompileControl.cpp
  source/core/tjs2/tjsArray.cpp
  source/core/tjs2/tjsRegExp.cpp
  source/core/tjs2/tjsDateParser.cpp
  source/core/tjs2/tjsDisassemble.cpp
  source/core/tjs2/tjsGlobalStringMap.cpp
  source/core/tjs2/tjsLex.cpp
  source/core/tjs2/tjsMT19937ar-cok.cpp
  source/core/tjs2/tjsInterface.cpp
  source/core/tjs2/tjsObject.cpp
  source/core/tjs2/tjsOctPack.cpp
  source/core/tjs2/tjsDate.cpp
  source/core/tjs2/tjsMath.cpp
  source/core/tjs2/tjsVariantString.cpp
  source/core/tjs2/tjsString.cpp
  source/core/tjs2/tjsVariant.cpp
  source/core/tjs2/tjs.tab.cpp
  source/core/tjs2/tjsBinarySerializer.cpp
  source/core/tjs2/tjsNative.cpp
  source/core/tjs2/tjsDictionary.cpp
  source/core/tjs2/tjsInterCodeExec.cpp
  source/core/tjs2/tjsUtils.cpp
  source/core/tjs2/tjsConfig.cpp
  source/core/tjs2/tjsNamespace.cpp
  source/core/tjs2/tjsdate.tab.cpp
  source/core/tjs2/tjsByteCodeLoader.cpp
  source/core/tjs2/tjsScriptCache.cpp
  source/core/tjs2/tjspp.tab.cpp
  source/core/tjs2/tjsObjectExtendable.cpp
  source/core/tjs2/tjs.cpp
  source/core/tjs2/tjsMessage.cpp
  source/core/tjs2/tjsError.cpp
  source/core/tjs2/tjsException.cpp
  source/core/tjs2/tjsSnprintf.cpp
  source/core/tjs2/tjsInterCodeGen.cpp
  source/core/tjs2/tjsRandomGenerator.cpp
  source/core/utils/ThreadIntf.cpp
  source/core/utils/DebugIntf.cpp
  source/core/utils/VelocityTracker.cpp
  source/core/utils/Random.cpp
  source/core/utils/TimerThread.cpp
  source/core/utils/uni_cp932.cpp
  source/core/utils/KAGParser.cpp
  source/core/utils/cp932_uni.cpp
  source/core/utils/ClipboardIntf.cpp
  source/core/utils/TimerIntf.cpp
  source/core/utils/PadIntf.cpp
  source/core/utils/MiscUtility.cpp
  source/core/utils/win32/ClipboardImpl.cpp
  source/core/utils/TVPTimer.cpp
  source/core/utils/TickCount.cpp
  source/core/environ/android/SystemControl.cpp
  source/core/environ/Application.cpp
  source/core/visual/BitmapIntf.cpp
  source/core/visual/WindowIntf.cpp
  source/core/visual/VideoOvlIntf.cpp
  source/core/visual/LoadPNG.cpp
  source/core/visual/MenuItemIntf.cpp
  source/core/visual/LayerIntf.cpp
  source/core/visual/FontSystem.cpp
  source/core/visual/GraphicsLoadThread.cpp
  source/core/visual/LayerManager.cpp
  source/core/visual/GraphicsLoaderIntf.cpp
  source/core/visual/FreeType.cpp
  source/core/visual/RenderManager.cpp
  source/core/visual/FreeTypeFontRasterizer.cpp
  source/core/visual/BitmapLayerTreeOwner.cpp
  source/core/visual/LayerTreeOwnerImpl.cpp
  source/core/visual/PrerenderedFont.cpp
  source/core/visual/gl/ResampleImage.cpp
  source/core/visual/gl/blend_function.cpp
  source/core/visual/gl/WeightFunctor.cpp
  source/core/visual/tvpgl.cpp
  source/core/visual/ComplexRect.cpp
  source/core/visual/CharacterData.cpp
  source/core/visual/LayerBitmapIntf.cpp
  source/core/visual/win32/WindowImpl.cpp
  source/core/visual/win32/VideoOvlImpl.cpp
  source/core/visual/win32/MenuItemImpl.cpp
  source/core/visual/win32/BitmapBitsAlloc.cpp
  source/core/visual/win32/LayerImpl.cpp
  source/core/visual/win32/GraphicsLoaderImpl.cpp
  source/core/visual/win32/DrawDevice.cpp
  source/core/visual/win32/BasicDrawDevice.cpp
  source/core/visual/win32/BitmapInfomation.cpp
  source/core/visual/win32/DInputMgn.cpp
  source/core/visual/win32/PassThroughDrawDevice.cpp
  source/core/visual/win32/LayerBitmapImpl.cpp
  source/core/visual/win32/TVPScreen.cpp
  source/core/visual/LoadTLG.cpp
  source/core/visual/TransIntf.cpp
  source/core/visual/SaveTLG5.cpp
  source/core/visual/LoadJPEG.cpp
  source/core/visual/ImageFunction.cpp
  source/core/visual/RectItf.cpp
  source/core/visual/SaveTLG6.cpp
  source/core/sdl2/stubs.cpp
  source/core/sound/PhaseVocoderFilter.cpp
  source/core/sound/SoundBufferBaseIntf.cpp
  source/core/sound/SoundBufferBaseImpl.cpp
  source/core/sound/MIDIIntf.cpp
  source/core/sound/VorbisWaveDecoder.cpp
  source/core/sound/PhaseVocoderDSP.cpp
  source/core/sound/WaveSegmentQueue.cpp
  source/core/sound/RealFFT.cpp
  source/core/sound/WaveFormatConverter.cpp
  source/core/sound/MathAlgorithms.cpp
  source/core/sound/win32/MIDIImpl.cpp
  source/core/sound/win32/WaveMixer.cpp
  source/core/sound/win32/WaveImpl.cpp
  source/core/sound/win32/CDDAImpl.cpp
  source/core/sound/WaveLoopManager.cpp
  source/core/sound/CDDAIntf.cpp
  source/core/sound/WaveIntf.cpp
  source/core/base/TextStream.cpp
  source/core/base/SystemIntf.cpp
  source/core/base/UtilStreams.cpp
  source/core/base/StorageIntf.cpp
  source/core/base/XP3Archive.cpp
  source/core/base/PluginIntf.cpp
  source/core/base/CharacterSet.cpp
  source/core/base/ScriptMgnIntf.cpp
  source/core/base/EventIntf.cpp
  source/core/base/android/StorageImpl.cpp
  source/core/base/android/GetLocalFileListAt.cpp
  source/core/base/win32/FileSelector.cpp
  source/core/base/win32/SystemImpl.cpp
  source/core/base/win32/PluginImpl.cpp
  source/core/base/win32/NativeEventQueue.cpp
  source/core/base/win32/ScriptMgnImpl.cpp
  source/core/base/win32/EventImpl.cpp
  source/core/base/win32/SysInitImpl.cpp
  source/core/base/SysInitIntf.cpp
  source/core/base/BinaryStream.cpp
  source/plugins/wutcwf.cpp
  source/plugins/varfile.cpp
  source/plugins/ncbind/ncbind.cpp
  source/plugins/LayerExBase.cpp
  source/plugins/saveStruct.cpp
  source/plugins/getSample.cpp
  source/plugins/layerExPerspective.cpp
  source/plugins/fftgraph.cpp
  source/plugins/InternalPlugins.cpp
  source/plugins/csvParser.cpp
  source/plugins/win32dialog.cpp
  source/plugins/dirlist.cpp
  source/core/utils/encoding/jis2unicode.c
  source/core/utils/encoding/gbk2unicode.c
  source/core/utils/md5.c
)

target_link_libraries(${PROJECT_NAME}
  stdc++
  pthread
  stdc++

  SDL2
  vita2d
  SceDisplay_stub
  SceCtrl_stub
  SceAudio_stub
  SceSysmodule_stub
  SceGxm_stub
  SceCommonDialog_stub
  SceTouch_stub
  SceHid_stub
  m
  z
  turbojpeg
  freetype
  png
  onigmo
  
  
  
  vorbisfile
  vorbis
  ogg


)

vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE sce_sys/icon0.png sce_sys/icon0.png
  FILE sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
  FILE sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
  FILE sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
)
