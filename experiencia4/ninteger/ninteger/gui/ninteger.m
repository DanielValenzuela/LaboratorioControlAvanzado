function varargout = ninteger(varargin)
% NINTEGER M-file for ninteger.fig
%      NINTEGER, by itself, creates a new NINTEGER or raises the existing
%      singleton*.
%
%      H = NINTEGER returns the handle to a new NINTEGER or the handle to
%      the existing singleton*.
%
%      NINTEGER('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in NINTEGER.M with the given input arguments.
%
%      NINTEGER('Property','Value',...) creates a new NINTEGER or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before ninteger_OpeningFunction gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to ninteger_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help ninteger

% Last Modified by GUIDE v2.5 05-Aug-2005 18:33:21

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ninteger_OpeningFcn, ...
                   'gui_OutputFcn',  @ninteger_OutputFcn, ...
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


% --- Executes just before ninteger is made visible.
function ninteger_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to ninteger (see VARARGIN)

% Choose default command line output for ninteger
handles.output = hObject;
% UIWAIT makes ninteger wait for user response (see UIRESUME)
% uiwait(handles.figure1);
handles.C = tf(0);
handles.plant = tf(0);
handles.open_loop = handles.C;
% Update handles structure
guidata(hObject, handles);


% --- Outputs from this function are returned to the command line.
function varargout = ninteger_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in radiobutton1.
function radiobutton1_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton1
button_state = get(hObject, 'Value');
if button_state == get(hObject, 'Max')
    handles.plant = tf(0);
    handles.open_loop = handles.C;
    set(handles.radiobutton2, 'Value', 0);
    set(handles.checkbox1, 'Enable', 'off');
    set(handles.edit_vargain, 'Enable', 'off');
    set(handles.edit_varzeros, 'Enable', 'off');
    set(handles.edit_varpoles, 'Enable', 'off');
    guidata(hObject, handles)
    redraw(handles);
elseif button_state == get(hObject,'Min')
    try
        handles.plant = evalin('base', get(handles.edit_plant, 'String'));
        handles.open_loop = handles.C * handles.plant;
        set(handles.radiobutton2, 'Value', 1);
        set(handles.checkbox1, 'Enable', 'on');
        set(handles.edit_vargain, 'Enable', 'on');
        set(handles.edit_varzeros, 'Enable', 'on');
        set(handles.edit_varpoles, 'Enable', 'on');
        guidata(hObject, handles)
        redraw(handles);
    catch
        handles.plant = tf(0);
        handles.open_loop = handles.C;
        set(handles.radiobutton2, 'Value', 0);
        set(hObject, 'Value', 1);
        set(handles.checkbox1, 'Enable', 'off');
        set(handles.edit_vargain, 'Enable', 'off');
        set(handles.edit_varzeros, 'Enable', 'off');
        set(handles.edit_varpoles, 'Enable', 'off');
        guidata(hObject, handles)
        errordlg(['Provide a valid LTI plant with the same sampling',...
                ' time of the controller.'], 'Error with the plant', 'modal')
    end
end

% --- Executes on button press in radiobutton2.
function radiobutton2_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton2
button_state = get(hObject, 'Value');
if button_state == get(hObject, 'Max')
    try
        handles.plant = evalin('base', get(handles.edit_plant, 'String'));
        handles.open_loop = handles.C * handles.plant;
        set(handles.radiobutton1, 'Value', 0);
        set(handles.checkbox1, 'Enable', 'on');
        set(handles.edit_vargain, 'Enable', 'on');
        set(handles.edit_varzeros, 'Enable', 'on');
        set(handles.edit_varpoles, 'Enable', 'on');
        guidata(hObject, handles)
        redraw(handles);
    catch
        handles.plant = tf(0);
        handles.open_loop = handles.C;
        set(handles.radiobutton1, 'Value', 1);
        set(hObject, 'Value', 0);
        set(handles.checkbox1, 'Enable', 'off');
        set(handles.edit_vargain, 'Enable', 'off');
        set(handles.edit_varzeros, 'Enable', 'off');
        set(handles.edit_varpoles, 'Enable', 'off');
        guidata(hObject, handles)
        errordlg(['Provide a valid LTI plant with the same sampling',...
                ' time of the controller.'], 'Error with the plant', 'modal')
    end
elseif button_state == get(hObject,'Min')
    handles.plant = tf(0);
    handles.open_loop = handles.C;
    set(handles.radiobutton1, 'Value', 1);
    set(handles.checkbox1, 'Enable', 'off');
    set(handles.edit_vargain, 'Enable', 'off');
    set(handles.edit_varzeros, 'Enable', 'off');
    set(handles.edit_varpoles, 'Enable', 'off');
    guidata(hObject, handles)
    redraw(handles);
end

% --- Executes during object creation, after setting all properties.
function popupmenu1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end


% --- Executes on selection change in popupmenu1.
function popupmenu1_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = get(hObject,'String') returns popupmenu1 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu1
redraw(handles);

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
if get(handles.radiobutton2, 'Value') == get(handles.radiobutton2, 'Max')
    try
        handles.plant = evalin('base', get(handles.edit_plant, 'String'));
        handles.open_loop = handles.C * handles.plant;
        guidata(hObject, handles)
        redraw(handles);
    catch
        handles.plant = tf(0);
        handles.open_loop = handles.C;
        set(handles.radiobutton1, 'Value', 1);
        set(handles.radiobutton2, 'Value', 0);
        set(handles.checkbox1, 'Enable', 'off');
        set(handles.edit_vargain, 'Enable', 'off');
        set(handles.edit_varzeros, 'Enable', 'off');
        set(handles.edit_varpoles, 'Enable', 'off');
        guidata(hObject, handles)
        redraw(handles);
        errordlg(['Provide a valid LTI plant with the same sampling',...
                ' time of the controller.'], 'Error with the plant', 'modal')
    end
end

% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
try
    temp = crone2Gui; % temp is used so that tf(0) is rejected and handles.C retained
    if dcgain(temp) ~= 0 | ~isempty(tzero(temp)) | ~isempty(pole(temp))
        handles.C = temp;
        handles.open_loop = handles.C;
        % Update handles structure
        guidata(hObject, handles);
        % this is for handling the case of there being a plant
        edit_plant_Callback(hObject, eventdata, handles);
        redraw(handles);
    end
catch
    ninteger
    errordlg('There was an error while building the controller.', 'Error', 'modal')
end


% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
try
    [w, gainC, phaseC, strings, G] = crone3Gui1;
    if isempty(w)
        return
    end
    temp = crone3Gui2(w, gainC, phaseC, G.Ts);
    % temp is used so that tf(0) is rejected and handles.C retained
    if dcgain(temp) ~= 0 | ~isempty(tzero(temp)) | ~isempty(pole(temp))
        handles.C = temp;
        handles.open_loop = handles.C;
        set(handles.radiobutton1, 'Value', 0);
        set(handles.radiobutton2, 'Value', 1);
        set(handles.checkbox1, 'Enable', 'on');
        set(handles.edit_vargain, 'Enable', 'on');
        set(handles.edit_varzeros, 'Enable', 'on');
        set(handles.edit_varpoles, 'Enable', 'on');
        set(handles.checkbox1, 'Value', 1);
        set(handles.edit_plant, 'String', strings.plant);
        set(handles.edit_vargain, 'String', strings.vargain);
        set(handles.edit_varzeros, 'String', strings.varzeros);
        set(handles.edit_varpoles, 'String', strings.varpoles);
        % Update handles structure
        guidata(hObject, handles);
        % this is for handling the plant and redrawing the plot
        edit_plant_Callback(hObject, eventdata, handles);
    end
catch
    ninteger
    errordlg('There was an error while building the controller.', 'Error', 'modal')
end



% --- Executes on button press in pushbuttonnipid.
function pushbuttonnipid_Callback(hObject, eventdata, handles)
% hObject    handle to pushbuttonnipid (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
temp = nipidGui; % temp is used so that tf(0) is rejected and handles.C retained
if dcgain(temp) ~= 0 | ~isempty(tzero(temp)) | ~isempty(pole(temp))
    handles.C = temp;
    handles.open_loop = handles.C;
    % Update handles structure
    guidata(hObject, handles);
    % this is for handling the case of there being a plant
    edit_plant_Callback(hObject, eventdata, handles);
    redraw(handles);
end


% --- Executes during object creation, after setting all properties.
function edit_wl_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_wl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



function edit_wl_Callback(hObject, eventdata, handles)
% hObject    handle to edit_wl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_wl as text
%        str2double(get(hObject,'String')) returns contents of edit_wl as a double
redraw(handles);

% --- Executes during object creation, after setting all properties.
function edit_wh_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_wh (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



function edit_wh_Callback(hObject, eventdata, handles)
% hObject    handle to edit_wh (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_wh as text
%        str2double(get(hObject,'String')) returns contents of edit_wh as a double
redraw(handles);

% --- Executes during object creation, after setting all properties.
function edit_tf_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_tf (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



function edit_tf_Callback(hObject, eventdata, handles)
% hObject    handle to edit_tf (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_tf as text
%        str2double(get(hObject,'String')) returns contents of edit_tf as a double
redraw(handles);


% --- Executes on button press in pushbuttonnipid_Save.
function pushbutton_Save_Callback(hObject, eventdata, handles)
% hObject    handle to pushbuttonnipid_Save (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if dcgain(handles.open_loop) == 0 & isempty(tzero(handles.open_loop)) &...
        isempty(pole(handles.open_loop))
    errordlg('There is no controller to save.', 'Error while saving', 'modal')
    return
end
name = get(handles.edit_name, 'String');
try
    eval(['global ' name]);
    eval([name ' = handles.C;']);
    evalin('base', ['global ' name]);
catch
    errordlg('The name you provided for the variable does not seem to be valid.', 'Error with the name', 'modal')
end


% --- Executes during object creation, after setting all properties.
function edit_name_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_name (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end


% --- Executes on button press in checkbox1.
function checkbox1_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox1
redraw(handles)

% --- Executes during object creation, after setting all properties.
function edit_varpoles_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_varpoles (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



function edit_varpoles_Callback(hObject, eventdata, handles)
% hObject    handle to edit_varpoles (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_varpoles as text
%        str2double(get(hObject,'String')) returns contents of edit_varpoles as a double
if get(handles.checkbox1, 'Value') == get(handles.checkbox1, 'Max')
    redraw(handles)
end

% --- Executes during object creation, after setting all properties.
function edit_varzeros_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_varzeros (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



function edit_varzeros_Callback(hObject, eventdata, handles)
% hObject    handle to edit_varzeros (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_varzeros as text
%        str2double(get(hObject,'String')) returns contents of edit_varzeros as a double
if get(handles.checkbox1, 'Value') == get(handles.checkbox1, 'Max')
    redraw(handles)
end

% --- Executes during object creation, after setting all properties.
function edit_vargain_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_vargain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



function edit_vargain_Callback(hObject, eventdata, handles)
% hObject    handle to edit_vargain (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_vargain as text
%        str2double(get(hObject,'String')) returns contents of edit_vargain as a double
if get(handles.checkbox1, 'Value') == get(handles.checkbox1, 'Max')
    redraw(handles)
end


% --- Redraws the plots
function redraw(handles)
% handles     needed for handling everything

wl = str2double(get(handles.edit_wl, 'String'));
if isnan(wl) | wl<=0
    errordlg('Provide a valid positive real number for the lower limit of the x-axis.', 'Error with wl', 'modal')
    return
end
wh = str2double(get(handles.edit_wh, 'String'));
if isnan(wh) | wh<=0
    errordlg('Provide a valid positive real number for the upper limit of the x-axis.', 'Error with wh', 'modal')
    return
end
if wh <= wl
    errordlg('The upper limit of the x-axis should be greater than the lower.', 'Error with wl and wh', 'modal')
    return
end
tfinal = str2double(get(handles.edit_tf, 'String'));
if isnan(tfinal)
    errordlg('Provide a valid real number for the final time instant.', 'Error with tf', 'modal')
    return
end
plot_type = get(handles.popupmenu1, 'Value');
switch plot_type
    case 1 % Bode diagram
        axes(handles.plot)
        plot(0) % this is for clearing whatever might appear behind in axes plot
        set(handles.plot, 'Visible', 'off');
        set(handles.plot1, 'Visible', 'on');
        set(handles.plot2, 'Visible', 'on');
        set(handles.edit_wl, 'Enable', 'on');
        set(handles.edit_wh, 'Enable', 'on');
        set(handles.edit_tf, 'Enable', 'off');
    case {2, 3} % Nichols and Nyquist diagrams
        axes(handles.plot1)
        plot(0) % this is for clearing whatever might appear behind in axes1 plot
        axes(handles.plot2)
        plot(0) % this is for clearing whatever might appear behind in axes2 plot
        set(handles.plot, 'Visible', 'on');
        set(handles.plot1, 'Visible', 'off');
        set(handles.plot2, 'Visible', 'off');
        set(handles.edit_wl, 'Enable', 'on');
        set(handles.edit_wh, 'Enable', 'on');
        set(handles.edit_tf, 'Enable', 'off');
    case {4, 5} % impulse and step responses
        axes(handles.plot1)
        plot(0) % this is for clearing whatever might appear behind in axes1 plot
        axes(handles.plot2)
        plot(0) % this is for clearing whatever might appear behind in axes2 plot
        set(handles.plot, 'Visible', 'on');
        set(handles.plot1, 'Visible', 'off');
        set(handles.plot2, 'Visible', 'off');
        set(handles.edit_wl, 'Enable', 'off');
        set(handles.edit_wh, 'Enable', 'off');
        set(handles.edit_tf, 'Enable', 'on');
    case 6 % zero and pole placement
        axes(handles.plot1)
        plot(0) % this is for clearing whatever might appear behind in axes1 plot
        axes(handles.plot2)
        plot(0) % this is for clearing whatever might appear behind in axes2 plot
        set(handles.plot, 'Visible', 'on');
        set(handles.plot1, 'Visible', 'off');
        set(handles.plot2, 'Visible', 'off');
        set(handles.edit_wl, 'Enable', 'off');
        set(handles.edit_wh, 'Enable', 'off');
        set(handles.edit_tf, 'Enable', 'off');
end
% This is for the case of parameter variations being given
flag_var = (get(handles.checkbox1, 'Value') == get(handles.checkbox1, 'Max'))...
    & strcmp(get(handles.checkbox1, 'Enable'), 'on');
if flag_var
    [zeros, poles, k] = zpkdata(handles.plant, 'v');
    zeros = sort(zeros);
    poles = sort(poles);
    try
        vargain = evalin('base', get(handles.edit_vargain, 'String'));
        if any(~isreal(vargain)) | any(ischar(vargain)) |...
                size(vargain, 1) ~= 1 | size(vargain, 2) ~= 2
            errordlg('The contents of the gain variations data variable are not valid.', 'Error with vargain', 'modal')
            set(handles.checkbox1, 'Value', 0)
            flag_var = 0;
        end
    catch
        errordlg('The name you provided for the gain variations data variable does not seem to be valid.', 'Error with vargain', 'modal')
        set(handles.checkbox1, 'Value', 0)
        flag_var = 0;
    end
    try
        varzeros = evalin('base', get(handles.edit_varzeros, 'String'));
        if any(ischar(varzeros)) | size(varzeros, 1) ~= length(zeros) |...
                (size(varzeros, 2) ~= 2 & length(zeros))
            errordlg('The contents of the zero variations data variable are not valid.', 'Error with varzeros', 'modal')
            set(handles.checkbox1, 'Value', 0)
            flag_var = 0;
        end
    catch
        errordlg('The name you provided for the zero variations data variable does not seem to be valid.', 'Error with varzeros', 'modal')
        set(handles.checkbox1, 'Value', 0)
        flag_var = 0;
    end
    try
        varpoles = evalin('base', get(handles.edit_varpoles, 'String'));
        if any(ischar(varpoles)) | size(varpoles, 1) ~= length(poles) |...
                (size(varpoles, 2) ~= 2 & length(poles))
            errordlg('The contents of the pole variations data variable are not valid.', 'Error with varpoles', 'modal')
            set(handles.checkbox1, 'Value', 0)
            flag_var = 0;
        end
    catch
        errordlg('The name you provided for the pole variations data variable does not seem to be valid.', 'Error with varpoles', 'modal')
        set(handles.checkbox1, 'Value', 0)
        flag_var = 0;
    end
end
% Last of all, plots are drawn
if dcgain(handles.open_loop) == 0 & isempty(tzero(handles.open_loop)) &...
        isempty(pole(handles.open_loop))
    return
end
if ~flag_var % plant parameter variations were not given
    switch plot_type
        case 1 % Bode diagram
            w = logspace(log10(wl), log10(wh));
            [gain, phase] = bode(handles.open_loop, w);
            gain = 20*log10(squeeze(gain));
            phase = squeeze(phase);
            axes(handles.plot1)
            semilogx(w, gain)
            grid
            xlabel('Frequency (rad/s)')
            ylabel('Gain (dB)')
            axes(handles.plot2)
            semilogx(w, phase)
            grid
            ylabel('Phase (degrees)')
        case 2 % Nichols diagram
            w = logspace(log10(wl), log10(wh));
            [gain, phase] = bode(handles.open_loop, w);
            gain = 20*log10(squeeze(gain));
            phase = squeeze(phase);
            axes(handles.plot)
            plot(phase, gain)
            ngrid
            xlabel('Phase (degrees)')
            ylabel('Gain (dB)')
        case 3 % Nyquist diagram
            w = logspace(log10(wl), log10(wh));
            response = squeeze(freqresp(handles.open_loop, w));
            axes(handles.plot)
            plot(real(response), imag(response), -1, 0, 'r.')
            grid
            xlabel('Real')
            ylabel('Imaginary')
        case 4 % impulse response
            [out, t] = impulse(handles.open_loop, tfinal);
            axes(handles.plot)
            plot(t, out)
            grid
            xlabel('Time (s)')
            ylabel('Impulse response')
        case 5 % step response
            [out, t] = step(handles.open_loop, tfinal);
            axes(handles.plot)
            plot(t, out)
            grid
            xlabel('Time (s)')
            ylabel('Step response')
        case 6 % pole and zero placement
            [zeros_open_loop, poles_open_loop] = zpkdata(handles.open_loop, 'v');
            axes(handles.plot)
            plot(real(zeros_open_loop), imag(zeros_open_loop), 'ob',...
                real(poles_open_loop), imag(poles_open_loop), 'xr')
            if handles.open_loop.Ts == 0
                grid
            else
                zgrid
            end
            xlabel('Real')
            ylabel('Imaginary')
    end
else % plant parameter variations were given
    Ts = handles.open_loop.Ts;
    variable = handles.open_loop.variable;
    switch plot_type
        case 1 % Bode diagram
            w = logspace(log10(wl), log10(wh));
            [gain, phase] = bode(handles.open_loop, w);
            gain = 20*log10(squeeze(gain));
            phase = squeeze(phase);
            % gain variations
            [gain2, phase2] =...
                bode(handles.open_loop * (k+vargain(1)) / k, w);
            gain2 = 20*log10(squeeze(gain2));
            phase2 = squeeze(phase2);
            [temp1, temp2] =...
                bode(handles.open_loop * (k+vargain(2)) / k, w);
            gain2 = [gain2, 20*log10(squeeze(temp1))];
            phase2 = [phase2, squeeze(temp2)];
            % zero variations
            for i=1:length(zeros)
                if imag(zeros(i)) > 0 % this is a complex zero that was already cared for
                    continue % skip this zero
                end
                for j=1:2
                    if imag(zeros(i))==0
                        correction = zpk(zeros(i)+varzeros(i,j), zeros(i), 1,...
                            Ts, 'Variable', variable);
                    else
                        correction = zpk([zeros(i)+varzeros(i,j)...
                                conj(zeros(i))+conj(varzeros(i,j))],...
                            [zeros(i) conj(zeros(i))], 1, Ts, 'Variable', variable);
                    end
                    [temp1, temp2] =...
                        bode(tf(ss(handles.open_loop * correction)), w);
                    gain2 = [gain2, 20*log10(squeeze(temp1))];
                    phase2 = [phase2, squeeze(temp2)];
                end
            end
            % pole variations
            for i=1:length(poles)
                if imag(poles(i)) > 0 % this is a complex zero that was already cared for
                    continue % skip this zero
                end
                for j=1:2
                    if imag(poles(i))==0
                        correction = zpk(poles(i)+varpoles(i,j), poles(i), 1,...
                            Ts, 'Variable', variable);
                    else
                        correction = zpk([poles(i)+varpoles(i,j)...
                                conj(poles(i))+conj(varpoles(i,j))],...
                            [poles(i) conj(poles(i))], 1, Ts, 'Variable', variable);
                    end
                    [temp1, temp2] =...
                        bode(tf(ss(handles.open_loop * correction)), w);
                    gain2 = [gain2, 20*log10(squeeze(temp1))];
                    phase2 = [phase2, squeeze(temp2)];
                end
            end
            % plot
            axes(handles.plot1)
            semilogx(w, gain2, 'm-', w, gain, 'b-')
            grid
            xlabel('Frequency (rad/s)')
            ylabel('Gain (dB)')
            axes(handles.plot2)
            semilogx(w, phase2, 'm-', w, phase, 'b-')
            grid
            ylabel('Phase (degrees)')
        case 2 % Nichols diagram
            w = logspace(log10(wl), log10(wh));
            [gain, phase] = bode(handles.open_loop, w);
            gain = 20*log10(squeeze(gain));
            phase = squeeze(phase);
            % gain variations
            [gain2, phase2] =...
                bode(handles.open_loop * (k+vargain(1)) / k, w);
            gain2 = 20*log10(squeeze(gain2));
            phase2 = squeeze(phase2);
            [temp1, temp2] =...
                bode(handles.open_loop * (k+vargain(2)) / k, w);
            gain2 = [gain2, 20*log10(squeeze(temp1))];
            phase2 = [phase2, squeeze(temp2)];
            % zero variations
            for i=1:length(zeros)
                if imag(zeros(i)) > 0 % this is a complex zero that was already cared for
                    continue % skip this zero
                end
                for j=1:2
                    if imag(zeros(i))==0
                        correction = zpk(zeros(i)+varzeros(i,j), zeros(i), 1,...
                            Ts, 'Variable', variable);
                    else
                        correction = zpk([zeros(i)+varzeros(i,j)...
                                conj(zeros(i))+conj(varzeros(i,j))],...
                            [zeros(i) conj(zeros(i))], 1, Ts, 'Variable', variable);
                    end
                    [temp1, temp2] =...
                        bode(tf(ss(handles.open_loop * correction)), w);
                    gain2 = [gain2, 20*log10(squeeze(temp1))];
                    phase2 = [phase2, squeeze(temp2)];
                end
            end
            % pole variations
            for i=1:length(poles)
                if imag(poles(i)) > 0 % this is a complex zero that was already cared for
                    continue % skip this zero
                end
                for j=1:2
                    if imag(poles(i))==0
                        correction = zpk(poles(i)+varpoles(i,j), poles(i), 1,...
                            Ts, 'Variable', variable);
                    else
                        correction = zpk([poles(i)+varpoles(i,j)...
                                conj(poles(i))+conj(varpoles(i,j))],...
                            [poles(i) conj(poles(i))], 1, Ts, 'Variable', variable);
                    end
                    [temp1, temp2] =...
                        bode(tf(ss(handles.open_loop * correction)), w);
                    gain2 = [gain2, 20*log10(squeeze(temp1))];
                    phase2 = [phase2, squeeze(temp2)];
                end
            end
            % plot
            axes(handles.plot)
            plot(phase2, gain2, 'm-', phase, gain, 'b-')
            ngrid
            xlabel('Phase (degrees)')
            ylabel('Gain (dB)')
        case 3 % Nyquist diagram
            w = logspace(log10(wl), log10(wh));
            response = squeeze(freqresp(handles.open_loop, w));
            % gain variations
            response2 =...
                squeeze(freqresp(handles.open_loop * (k+vargain(1)) / k, w));
            response2 = [response2, squeeze(freqresp(handles.open_loop *...
                        (k+vargain(2)) / k, w))];
            % zero variations
            for i=1:length(zeros)
                if imag(zeros(i)) > 0 % this is a complex zero that was already cared for
                    continue % skip this zero
                end
                for j=1:2
                    if imag(zeros(i))==0
                        correction = zpk(zeros(i)+varzeros(i,j), zeros(i), 1,...
                            Ts, 'Variable', variable);
                    else
                        correction = zpk([zeros(i)+varzeros(i,j)...
                                conj(zeros(i))+conj(varzeros(i,j))],...
                            [zeros(i) conj(zeros(i))], 1, Ts, 'Variable', variable);
                    end
                    response2 = [response2,...
                            squeeze(freqresp(handles.open_loop * correction,...
                            w))];
                end
            end
            % pole variations
            for i=1:length(poles)
                if imag(poles(i)) > 0 % this is a complex zero that was already cared for
                    continue % skip this zero
                end
                for j=1:2
                    if imag(poles(i))==0
                        correction = zpk(poles(i)+varpoles(i,j), poles(i), 1,...
                            Ts, 'Variable', variable);
                    else
                        correction = zpk([poles(i)+varpoles(i,j)...
                                conj(poles(i))+conj(varpoles(i,j))],...
                            [poles(i) conj(poles(i))], 1, Ts, 'Variable', variable);
                    end
                    response2 = [response2,...
                            squeeze(freqresp(handles.open_loop * correction,...
                            w))];
                end
            end
            % plot
            axes(handles.plot)
            plot(real(response2), imag(response2), 'm-',...
                real(response), imag(response), 'b-', -1, 0, 'r.')
            grid
            xlabel('Real')
            ylabel('Imaginary')
        case 4 % impulse response
            if Ts>0
                t = 0:Ts:tfinal;
            else
                t = 0:tfinal/100:tfinal;
            end
            out = impulse(handles.open_loop, t);
            % gain variations
            out2 = impulse(handles.open_loop * (k+vargain(1)) / k, t);
            out2 = [out2,...
                    impulse(handles.open_loop * (k+vargain(2)) / k, t)];
            % zero variations
            for i=1:length(zeros)
                if imag(zeros(i)) > 0 % this is a complex zero that was already cared for
                    continue % skip this zero
                end
                for j=1:2
                    if imag(zeros(i))==0
                        correction = zpk(zeros(i)+varzeros(i,j), zeros(i), 1,...
                            Ts, 'Variable', variable);
                    else
                        correction = zpk([zeros(i)+varzeros(i,j)...
                                conj(zeros(i))+conj(varzeros(i,j))],...
                            [zeros(i) conj(zeros(i))], 1, Ts, 'Variable', variable);
                    end
                    out2 = [out2,...
                            impulse(handles.open_loop * correction, t)];
                end
            end
            % pole variations
            for i=1:length(poles)
                if imag(poles(i)) > 0 % this is a complex zero that was already cared for
                    continue % skip this zero
                end
                for j=1:2
                    if imag(poles(i))==0
                        correction = zpk(poles(i)+varpoles(i,j), poles(i), 1,...
                            Ts, 'Variable', variable);
                    else
                        correction = zpk([poles(i)+varpoles(i,j)...
                                conj(poles(i))+conj(varpoles(i,j))],...
                            [poles(i) conj(poles(i))], 1, Ts, 'Variable', variable);
                    end
                    out2 = [out2,...
                            impulse(handles.open_loop * correction, t)];
                end
            end
            % plot
            axes(handles.plot)
            plot(t, out2, 'm-', t, out, 'b-')
            grid
            xlabel('Time (s)')
            ylabel('Impulse response')
        case 5 % step response
            if Ts>0
                t = 0:Ts:tfinal;
            else
                t = 0:tfinal/100:tfinal;
            end
            out = step(handles.open_loop, t);
            % gain variations
            out2 = step(handles.open_loop * (k+vargain(1)) / k, t);
            out2 = [out2,...
                    step(handles.open_loop * (k+vargain(2)) / k, t)];
            % zero variations
            for i=1:length(zeros)
                if imag(zeros(i)) > 0 % this is a complex zero that was already cared for
                    continue % skip this zero
                end
                for j=1:2
                    if imag(zeros(i))==0
                        correction = zpk(zeros(i)+varzeros(i,j), zeros(i), 1,...
                            Ts, 'Variable', variable);
                    else
                        correction = zpk([zeros(i)+varzeros(i,j)...
                                conj(zeros(i))+conj(varzeros(i,j))],...
                            [zeros(i) conj(zeros(i))], 1, Ts, 'Variable', variable);
                    end
                    out2 = [out2,...
                            step(handles.open_loop * correction, t)];
                end
            end
            % pole variations
            for i=1:length(poles)
                if imag(poles(i)) > 0 % this is a complex zero that was already cared for
                    continue % skip this zero
                end
                for j=1:2
                    if imag(poles(i))==0
                        correction = zpk(poles(i)+varpoles(i,j), poles(i), 1,...
                            Ts, 'Variable', variable);
                    else
                        correction = zpk([poles(i)+varpoles(i,j)...
                                conj(poles(i))+conj(varpoles(i,j))],...
                            [poles(i) conj(poles(i))], 1, Ts, 'Variable', variable);
                    end
                    out2 = [out2,...
                            step(handles.open_loop * correction, t)];
                end
            end
            % plot
            axes(handles.plot)
            plot(t, out2, 'm-', t, out, 'b-')
            grid
            xlabel('Time (s)')
            ylabel('Step response')
        case 6 % pole and zero placement
            [zeros_open_loop, poles_open_loop] = zpkdata(handles.open_loop, 'v');
            % zero variations
            zeros2 = [];
            for i=1:length(zeros)
                if imag(zeros(i))>0
                    zeros2 = [zeros2; zeros(i)+varzeros(i-1,1);...
                            zeros(i)+varzeros(i-1,2)];
                else
                    zeros2 = [zeros2; zeros(i)+varzeros(i,1);...
                            zeros(i)+varzeros(i,2)];
                end
            end
            % pole variations
            poles2 = [];
            for i=1:length(poles)
                if imag(poles(i))>0
                    poles2 = [poles2; poles(i)+conj(varpoles(i-1,1));...
                            poles(i)+conj(varpoles(i-1,2))];
                else
                    poles2 = [poles2; poles(i)+varpoles(i,1);...
                            poles(i)+varpoles(i,2)];
                end
            end
            % plot
            axes(handles.plot)
            plot(real(zeros2), imag(zeros2), 'om',...
                real(poles2), imag(poles2), 'xg',...
                real(zeros_open_loop), imag(zeros_open_loop), 'ob',...
                real(poles_open_loop), imag(poles_open_loop), 'xr')
            if handles.open_loop.Ts == 0
                grid
            else
                zgrid
            end
            xlabel('Real')
            ylabel('Imaginary')
    end
end