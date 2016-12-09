function varargout = crone2Gui(varargin)
% CRONE2GUI M-file for crone2Gui.fig
%      CRONE2GUI, by itself, creates a new CRONE2GUI or raises the existing
%      singleton*.
%
%      H = CRONE2GUI returns the handle to a new CRONE2GUI or the handle to
%      the existing singleton*.
%
%      CRONE2GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in CRONE2GUI.M with the given input arguments.
%
%      CRONE2GUI('Property','Value',...) creates a new CRONE2GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before crone2Gui_OpeningFunction gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to crone2Gui_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help crone2Gui

% Last Modified by GUIDE v2.5 15-Sep-2003 09:54:25

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @crone2Gui_OpeningFcn, ...
                   'gui_OutputFcn',  @crone2Gui_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin & isstr(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before crone2Gui is made visible.
function crone2Gui_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to crone2Gui (see VARARGIN)

% Choose default command line output for crone2Gui
handles.output = tf(0);
handles.w = [];
handles.plant = tf(0);
handles.gain = [];
handles.phase = [];
% Update handles structure
guidata(hObject, handles);
% legends are added
axes(handles.axes_gain)
xlabel('Frequency (rad/s)')
ylabel('Gain (dB)')
axes(handles.axes_phase)
ylabel('Phase (degrees)')
% UIWAIT makes crone2Gui wait for user response (see UIRESUME)
uiwait(handles.crone2Gui);



% --- Outputs from this function are returned to the command line.
function varargout = crone2Gui_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
if ~isempty(handles)
    varargout{1} = handles.output;
    delete(handles.crone2Gui);
else
    varargout{1} = tf(0);
end


% --- Executes on button press in radiobutton_Gain_data.
function radiobutton_Gain_data_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton_Gain_data (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton_Gain_data
button_state = get(hObject, 'Value');
if button_state == get(hObject, 'Max')
    set(handles.radiobutton_Unit_gain, 'Value', 0);
    try
        handles.gain = evalin('base', get(handles.edit_gain, 'String'));
        if any(~isreal(handles.gain)) | any(ischar(handles.gain))
            set(handles.radiobutton_Unit_gain, 'Value', 1);
            set(hObject, 'Value', 0);
            errordlg('Gains (in dB) must be positive.', 'Error with the gain', 'modal')
        end
        if size(handles.gain, 2)>1 | length(handles.gain)~=length(handles.w)
            set(handles.radiobutton_Unit_gain, 'Value', 1);
            set(hObject, 'Value', 0);
            errordlg('The list of gains must be a column vector of positive real numbers with the same size of the list of frequencies.', 'Error with the gain', 'modal')
        end
    catch
        set(handles.radiobutton_Unit_gain, 'Value', 1);
        set(hObject, 'Value', 0);
        errordlg('The name you provided for the gain data variable does not seem to be valid, or else its contents are not.', 'Error with the name', 'modal')
    end
else
    set(handles.radiobutton_Unit_gain, 'Value', 1);
end
guidata(hObject, handles);
redraw(handles)


% --- Executes on button press in radiobutton_Unit_gain.
function radiobutton_Unit_gain_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton_Unit_gain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton_Unit_gain
button_state = get(hObject, 'Value');
if button_state == get(hObject, 'Max')
    set(handles.radiobutton_Gain_data, 'Value', 0);
else
    set(handles.radiobutton_Gain_data, 'Value', 1);
    try
        handles.gain = evalin('base', get(handles.edit_gain, 'String'));
        if any(~isreal(handles.gain)) | any(ischar(handles.gain))
            set(handles.radiobutton_Gain_data, 'Value', 0);
            set(hObject, 'Value', 1);
            errordlg('Gains (in dB) must be positive.', 'Error with the gain', 'modal')
        end
        if size(handles.gain, 2)>1
            set(handles.radiobutton_Gain_data, 'Value', 0);
            set(hObject, 'Value', 1);
            errordlg('The list of gains must be a column vector of positive real numbers.', 'Error with the gain', 'modal')
        end
    catch
        set(handles.radiobutton_Gain_data, 'Value', 0);
        set(hObject, 'Value', 1);
        errordlg('The name you provided for the gain data variable does not seem to be valid, or else its contents are not.', 'Error with the name', 'modal')
    end
end
guidata(hObject, handles);
redraw(handles)


% --- Executes on button press in radiobutton_continuous.
function radiobutton_continuous_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton_continuous (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton_continuous
button_state = get(hObject, 'Value');
if button_state == get(hObject, 'Max')
    set(handles.radiobutton_Ts, 'Value', 0);
elseif button_state == get(hObject,'Min')
    set(handles.radiobutton_Ts, 'Value', 1);
end


% --- Executes on button press in radiobutton_Ts.
function radiobutton_Ts_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton_Ts (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton_Ts
button_state = get(hObject, 'Value');
if button_state == get(hObject, 'Max')
    set(handles.radiobutton_continuous, 'Value', 0);
elseif button_state == get(hObject,'Min')
    set(handles.radiobutton_continuous, 'Value', 1);
end


% --- Executes on button press in pushbutton_OK.
function pushbutton_OK_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_OK (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if isempty(handles.w)
    errordlg('You must provide a valid list of frequencies.', 'Error with w', 'modal')
    return
end
if isempty(handles.phase)
    errordlg(['You must provide a phase behaviour to mimic, either by inputting'...
            'a list of phases or by giving a plant to complement.'], 'Error with the phase', 'modal')
    return
end
n = str2double(get(handles.edit_n, 'String'));
if isnan(n) | n<=0 | ~isinteger(n)
    errordlg('Specify the number of zeros and poles with a valid positive integer number.', 'Error with n', 'modal')
    return
end
if get(handles.radiobutton_Ts, 'Value') == get(handles.radiobutton_Ts, 'Max')
    Ts = str2double(get(handles.edit_Ts, 'String'));
    if isnan(Ts) | Ts<=0
        errordlg('Provide a valid positive real number for the sampling time.', 'Error with Ts', 'modal')
        return
    end
else
    Ts = 0;
end
if get(handles.radiobutton_Gain_data, 'Value') ==...
        get(handles.radiobutton_Gain_data, 'Max')
    if Ts
        handles.output = crone2z(handles.w, handles.gain, handles.phase, n, Ts);
    else
        handles.output = crone2(handles.w, handles.gain, handles.phase, n);
    end
else
    w1 = str2double(get(handles.edit_w1, 'String'));
    if isnan(w1) | n<=0
        errordlg('Provide a valid positive real number for the unit gain frequency.', 'Error with w1', 'modal')
        return
    end
    if Ts
        handles.output = crone2z(handles.w, [], handles.phase, n, Ts, w1);
    else
        handles.output = crone2(handles.w, [], handles.phase, n, w1);
    end
end
guidata(hObject, handles);
uiresume


% --- Executes on button press in pushbutton_Cancel.
function pushbutton_Cancel_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_Cancel (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
uiresume % this handles the closing of the function


% --- Executes during object creation, after setting all properties.
function edit_Ts_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_Ts (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



% --- Executes during object creation, after setting all properties.
function edit_w1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_w1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



% --- Executes during object creation, after setting all properties.
function edit_gain_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_gain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



function edit_gain_Callback(hObject, eventdata, handles)
% hObject    handle to edit_gain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_gain as text
%        str2double(get(hObject,'String')) returns contents of edit_gain as a double
if get(handles.radiobutton_Gain_data, 'Value') ==...
        get(handles.radiobutton_Gain_data, 'Max')
    try
        handles.gain = evalin('base', get(handles.edit_gain, 'String'));
        if any(~isreal(handles.gain)) | any(ischar(handles.gain))
            set(handles.radiobutton_Unit_gain, 'Value', 1);
            set(handles.radiobutton_Gain_data, 'Value', 0);
            errordlg('Gains (in dB) must be real.', 'Error with the gain', 'modal')
        end
        if size(handles.gain, 2)>1 | length(handles.gain)~=length(handles.w)
            set(handles.radiobutton_Unit_gain, 'Value', 1);
            set(handles.radiobutton_Gain_data, 'Value', 0);
            errordlg('The list of gains must be a column vector of real numbers with the same size of the list of frequencies.', 'Error with the gain', 'modal')
        end
    catch
        set(handles.radiobutton_Unit_gain, 'Value', 1);
        set(handles.radiobutton_Gain_data, 'Value', 0);
        errordlg('The name you provided for the gain data variable does not seem to be valid, or else its contents are not.', 'Error with the name', 'modal')
    end
    redraw(handles)
end


% --- Executes on button press in radiobutton_phase.
function radiobutton_phase_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton_phase (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton_phase
button_state = get(hObject, 'Value');
if button_state == get(hObject, 'Max')
    set(handles.radiobutton_complement, 'Value', 0);
    try
        handles.phase = evalin('base', get(handles.edit_phase, 'String'));
        if any(~isreal(handles.phase)) | any(ischar(handles.phase))
            set(handles.radiobutton_complement, 'Value', 1);
            set(hObject, 'Value', 0);
            errordlg('Phases (in degrees) must be real.', 'Error with the phase', 'modal')
            edit_plant_Callback(hObject, eventdata, handles);
        end
        if size(handles.phase, 2)>1 | length(handles.phase)~=length(handles.w)
            set(handles.radiobutton_complement, 'Value', 1);
            set(hObject, 'Value', 0);
            errordlg('The list of phases must be a column vector of real numbers with the same size of the list of frequencies.', 'Error with the phase', 'modal')
            edit_plant_Callback(hObject, eventdata, handles);
        end
    catch
        set(handles.radiobutton_complement, 'Value', 1);
        set(hObject, 'Value', 0);
        errordlg('The name you provided for the phase data variable does not seem to be valid, or else its contents are not.', 'Error with the name', 'modal')
        edit_plant_Callback(hObject, eventdata, handles);
   end
else
    set(handles.radiobutton_complement, 'Value', 1);
end
guidata(hObject, handles);
redraw(handles)

% --- Executes on button press in radiobutton_complement.
function radiobutton_complement_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton_complement (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton_complement
button_state = get(hObject, 'Value');
if button_state == get(hObject, 'Max')
    set(handles.radiobutton_phase, 'Value', 0);
    edit_plant_Callback(hObject, eventdata, handles);
else
    set(handles.radiobutton_phase, 'Value', 1);
    try
        handles.phase = evalin('base', get(handles.edit_phase, 'String'));
        if any(~isreal(handles.phase)) | any(ischar(handles.phase))
            set(handles.radiobutton_phase, 'Value', 0);
            set(hObject, 'Value', 1);
            errordlg('Phases (in degrees) must be real.', 'Error with the phase', 'modal')
            edit_plant_Callback(hObject, eventdata, handles);
        end
        if size(handles.phase, 2)>1
            set(handles.radiobutton_phase, 'Value', 0);
            set(hObject, 'Value', 1);
            errordlg('The list of phases must be a column vector of real numbers.', 'Error with the phase', 'modal')
            edit_plant_Callback(hObject, eventdata, handles);
        end
    catch
        set(handles.radiobutton_phase, 'Value', 0);
        set(hObject, 'Value', 1);
        errordlg('The name you provided for the phase data variable does not seem to be valid, or else its contents are not.', 'Error with the name', 'modal')
        edit_plant_Callback(hObject, eventdata, handles);
    end
end
guidata(hObject, handles);
redraw(handles)

% --- Executes during object creation, after setting all properties.
function edit_order_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_order (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



function edit_order_Callback(hObject, eventdata, handles)
% hObject    handle to edit_order (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_order as text
%        str2double(get(hObject,'String')) returns contents of edit_order as a double
edit_plant_Callback(hObject, eventdata, handles);


% --- Executes during object creation, after setting all properties.
function edit_phase_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_phase (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



function edit_phase_Callback(hObject, eventdata, handles)
% hObject    handle to edit_phase (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_phase as text
%        str2double(get(hObject,'String')) returns contents of edit_phase as a double
if get(handles.radiobutton_phase, 'Value') ==...
        get(handles.radiobutton_phase, 'Max')
    try
        handles.phase = evalin('base', get(handles.edit_phase, 'String'));
        if any(~isreal(handles.phase)) | any(ischar(handles.phase))
            set(handles.radiobutton_complement, 'Value', 1);
            set(handles.radiobutton_phase, 'Value', 0);
            errordlg('Phases (in degrees) must be real.', 'Error with the phase', 'modal')
            edit_plant_Callback(hObject, eventdata, handles);
        end
        if size(handles.phase, 2)>1 | length(handles.phase)~=length(handles.w)
            set(handles.radiobutton_complement, 'Value', 1);
            set(handles.radiobutton_phase, 'Value', 0);
            errordlg('The list of phases must be a column vector of real numbers with the same size of the list of frequencies.', 'Error with the phase', 'modal')
            edit_plant_Callback(hObject, eventdata, handles);
        end
    catch
        set(handles.radiobutton_complement, 'Value', 1);
        set(handles.radiobutton_phase, 'Value', 0);
        errordlg('The name you provided for the phase data variable does not seem to be valid, or else its contents are not.', 'Error with the name', 'modal')
        edit_plant_Callback(hObject, eventdata, handles);
    end
end
guidata(hObject, handles);
redraw(handles)

% --- Executes during object creation, after setting all properties.
function edit_plant_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_plant (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



function edit_plant_Callback(hObject, eventdata, handles)
% hObject    handle to edit_plant (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_plant as text
%        str2double(get(hObject,'String')) returns contents of edit_plant as a double
try
    handles.plant = evalin('base', get(handles.edit_plant, 'String'));
    guidata(hObject, handles)
    [gain, phase] = bode(handles.plant, handles.w);
    order = str2double(get(handles.edit_order, 'String'));
    if isnan(order)
        handles.plant = tf(0);
        handles.phase = [];
        guidata(hObject, handles);
        redraw(handles);
        errordlg('Provide a valid real number for the order of the open-loop.', 'Error with the order', 'modal')
        return
    end
    handles.phase = order * 90 - squeeze(phase);
catch
    handles.plant = tf(0);
    handles.phase = [];
    set(handles.edit_plant, 'String', '');
    errordlg('Provide a valid LTI plant.', 'Error with the plant', 'modal')
end
guidata(hObject, handles)
redraw(handles);


% --- Executes during object creation, after setting all properties.
function listbox1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to listbox1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end


% --- Executes on button press in pushbutton_delete.
function pushbutton_delete_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_delete (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
index_selected = get(handles.listbox1, 'Value');
handles.w = handles.w(setdiff(1:end, index_selected));
set(handles.listbox1, 'Value', []); % nothing may be selected in the end
set(handles.listbox1, 'String', num2str(handles.w));
% Update handles structure
guidata(hObject, handles);
% this prevents errors
if get(handles.radiobutton_Gain_data, 'Value') ==...
        get(handles.radiobutton_Gain_data, 'Max')
    set(handles.radiobutton_Gain_data, 'Value', 0)
    set(handles.radiobutton_Unit_gain, 'Value', 1)
end
if get(handles.radiobutton_phase, 'Value') ==...
        get(handles.radiobutton_phase, 'Max')
    set(handles.radiobutton_phase, 'Value', 0)
    set(handles.radiobutton_complement, 'Value', 1)
end
edit_plant_Callback(hObject, eventdata, handles);

% --- Executes on button press in pushbutton_add.
function pushbutton_add_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_add (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
wnew = str2double(get(handles.edit_add, 'String'));
if isnan(wnew) | ~isreal(wnew) | wnew<=0
    errordlg('Provide a valid positive real number for the new frequency.', 'Error with w', 'modal')
    return
end
handles.w = unique([handles.w; wnew]);
set(handles.listbox1, 'String', num2str(handles.w));
% Update handles structure
guidata(hObject, handles);
set(handles.edit_add, 'String', ''); % this clears the field
% this prevents errors
if get(handles.radiobutton_Gain_data, 'Value') ==...
        get(handles.radiobutton_Gain_data, 'Max')
    set(handles.radiobutton_Gain_data, 'Value', 0)
    set(handles.radiobutton_Unit_gain, 'Value', 1)
end
if get(handles.radiobutton_phase, 'Value') ==...
        get(handles.radiobutton_phase, 'Max')
    set(handles.radiobutton_phase, 'Value', 0)
    set(handles.radiobutton_complement, 'Value', 1)
end
edit_plant_Callback(hObject, eventdata, handles);

% --- Executes on button press in pushbutton_load.
function pushbutton_load_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_load (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
name = get(handles.edit_load, 'String');
try
    w = evalin('base', name); % contents of variable name
    % look for complex or negative numbers and for characters
    if any(~isreal(w)) | any(w<=0) | any(ischar(w))
        errordlg('Frequencies must be real and positive.', 'Error with w', 'modal')
        return
    end
    if size(w, 2)>1
        errordlg('The list of frequencies must be a column vector of positive real numbers.', 'Error with w', 'modal')
        return
    end
    set(handles.listbox1, 'String', num2str(unique(w))); % unique also sorts
    handles.w = w;
    % Update handles structure
    guidata(hObject, handles);
    % this prevents errors
    if get(handles.radiobutton_Gain_data, 'Value') ==...
            get(handles.radiobutton_Gain_data, 'Max')
        set(handles.radiobutton_Gain_data, 'Value', 0)
        set(handles.radiobutton_Unit_gain, 'Value', 1)
    end
    if get(handles.radiobutton_phase, 'Value') ==...
            get(handles.radiobutton_phase, 'Max')
        set(handles.radiobutton_phase, 'Value', 0)
        set(handles.radiobutton_complement, 'Value', 1)
    end
    edit_plant_Callback(hObject, eventdata, handles);
catch
    errordlg('The name you provided for the frequency data variable does not seem to be valid, or else its contents are not.', 'Error with the name', 'modal')
end

% --- Executes during object creation, after setting all properties.
function edit_add_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_add (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



% --- Executes during object creation, after setting all properties.
function edit_load_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_load (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



% --- Redraws the plots
function redraw(handles)
% handles     needed for handling everything

% if there are no frequencies no plot can be shown
if isempty(handles.w)
    return
end

% plotting the gain
if get(handles.radiobutton_Gain_data, 'Value') ==...
        get(handles.radiobutton_Gain_data, 'Max')
    axes(handles.axes_gain)
    semilogx(handles.w, handles.gain, '.r')
    actual = axis;
    lims = [10^(floor(log10(min(handles.w)))) 10^(ceil(log10(max(handles.w))))];
    axis([lims actual(3:4)])
    xlabel('Frequency (rad/s)')
    ylabel('Gain (dB)')
    grid
else
    axes(handles.axes_gain)
    plot(-1) % this is a stupid way of erasing the slate!
    axis([0 1 0 1])
    xlabel('Frequency (rad/s)')
    ylabel('Gain (dB)')
end

% plotting the phase
if get(handles.radiobutton_phase, 'Value') ==...
        get(handles.radiobutton_phase, 'Max')
    axes(handles.axes_phase)
    semilogx(handles.w, handles.phase, '.r')
    actual = axis;
    lims = [10^(floor(log10(min(handles.w)))) 10^(ceil(log10(max(handles.w))))];
    axis([lims actual(3:4)])
    ylabel('Phase (degrees)')
    grid
elseif dcgain(handles.plant)==0
    axes(handles.axes_phase)
    plot(-1) % this is a stupid way of erasing the slate!
    axis([0 1 0 1])
    ylabel('Phase (degrees)')
else
    try
        [gain, phase, w] = bode(handles.plant, {min(handles.w) max(handles.w)});
    catch
        [gain, phase, w] = bode(handles.plant, min(handles.w));
    end
    axes(handles.axes_phase)
    semilogx(w, squeeze(phase), handles.w, handles.phase, '.r')
    actual = axis;
    lims = [10^(floor(log10(min(handles.w)))) 10^(ceil(log10(max(handles.w))))];
    try
        axis([lims actual(3:4)])
    end
    ylabel('Phase (degrees)')
    grid
end


% --- Executes during object creation, after setting all properties.
function edit_n_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_n (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end