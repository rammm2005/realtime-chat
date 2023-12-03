import {MultiChatSocket, MultiChatWindow, useMultiChatLogic} from 'react-chat-engine-advanced'

const ChatsPage = (props) => {
    const chatProps = useMultiChatLogic('4bd2153f-4d54-4db2-a18e-dbf769aa0af7', props.user.username, props.user.secret);
    return (
        <div style={{height: '100vh'}}>
            <MultiChatSocket {...chatProps} />
            <MultiChatWindow {...chatProps} style={{height:'100%'}}/>
        </div>
    );
}

export default ChatsPage;