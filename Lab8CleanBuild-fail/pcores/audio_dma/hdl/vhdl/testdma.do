##didn't know if this would help or hamper. I think this was a pretty good do-file that Eric and I put together
##It's only a suggestion and just because your code passes through this pretty well doesn't mean that it is right
##especially since I can't guarantee that this do-file is right.
##Another note, just because your code DOESN'T work right with this doesn't mean it ISN'T right (if you can follow)
quit -sim

vcom audio_channel.vhd
vcom audio_dma.vhd

vsim work.audio_dma

alias f "force"
alias r "run 20ns"
# default Bus
alias defaultBus { f OPB_select 0;f OPB_ABus 16#0;f OPB_DBus 16#0;f OPB_RNW 0;f OPB_MGrant 0;f OPB_timeout 0;f OPB_xferAck 0;}

alias giveBus {f OPB_MGrant 1;}
alias tAck    {f OPB_xferAck 1;}

add wave OPB_Clk OPB_Rst
add wave sl_state_reg sl_state_next
add wave m_state_reg m_state_next
add wave M_request
add wave opb_select
add wave -hex OPB_ABus
add wave -hex OPB_DBus
add wave -hex Sl_DBus
add wave -hex destinationAddr
add wave Sl_xferAck OPB_RNW OPB_seqAddr
add wave AC97Int
add wave stopAudioPlayback
add wave playingChannelExists
add wave /audio_dma/g1__5/achnl/channel_play_channel  #I had an additional component named audio_dma that was used
add wave -hex /audio_dma/g1__5/achnl/channel_sound_addr
add wave -hex /audio_dma/g1__5/achnl/channel_length_of_sound
add wave -hex /audio_dma/g1__5/achnl/channel_sample_num
add wave /audio_dma/g1__0/achnl/channel_loop_audio
add wave channel_on
add wave -hex channel_data_out(5)
add wave channel_en setAddr setLength setOtherData playChannel


force OPB_Clk 1,0 10ns -r 20ns
force OPB_Rst 1
force OPB_select 0
force OPB_ABus 16#0
force OPB_DBus 16#0
force OPB_seqAddr 0
force OPB_RNW 0
force AC97Int 0
force OPB_errAck 0
force OPB_MGrant 0
force OPB_retry 0
force OPB_timeout 0
force OPB_xferAck 0
force OPB_BE 0
run 35ns
f OPB_Rst 0

#finish resetting
defaultBus
r

defaultBus
r

#set destination address
force OPB_ABUS 16#40090100
force OPB_DBUS 16#40600004
force opb_rnw 0
force opb_select 1
r
r

defaultBus
r

#set other data
force OPB_ABUS 16#40090104
force OPB_DBUS 16#00000040
force opb_rnw 0
force opb_select 1
r
r

defaultBus
r

#set addr data for channel 5
force OPB_ABUS 16#40090050
force OPB_DBUS 16#ABCD0100
force opb_rnw 0
force opb_select 1
r
r
defaultBus
r

#set length data for channel 5
force OPB_ABUS 16#40090054
force OPB_DBUS 16#00000010
force opb_rnw 0
force opb_select 1
r
r
defaultBus
r

#set length data for channel 5
force OPB_ABUS 16#4009005C
force opb_rnw 0
force opb_select 1
r
r
defaultBus
r



force AC97Int 1
r
giveBus
r
tAck
r
defaultBus
r
giveBus
r
tAck
r
defaultBus
r
r
r
giveBus
r
tAck
r
defaultBus
r
giveBus
r
tAck
r
defaultBus
r
giveBus
r
tAck
r
defaultBus
r
giveBus
r
tAck
r
defaultBus
r
giveBus
r
tAck
r
defaultBus
r
giveBus
r
tAck
r
defaultBus
r
giveBus
r
tAck
r
defaultBus
r
giveBus
r
tAck
r
defaultBus
r

giveBus
r
tAck
r
defaultBus
r
giveBus
r
tAck
r
defaultBus
r
giveBus
r
tAck
r
defaultBus
r
giveBus
r
tAck
r
defaultBus
r
giveBus
r
tAck
r
defaultBus
r
giveBus
r
tAck
r
defaultBus
r
