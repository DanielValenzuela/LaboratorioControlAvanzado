function varargout = nipidGui(varargin)
% NIPIDGUI M-file for nipidGui.fig
%      NIPIDGUI, by itself, creates a new NIPIDGUI or raises the existing
%      singleton*.
%
%      H = NIPIDGUI returns the handle to a new NIPIDGUI or the handle to
%      the existing singleton*.
%
%      NIPIDGUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in NIPIDGUI.M with the given input arguments.
%
%      NIPIDGUI('Property','Value',...) creates a new NIPIDGUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before nipidGui_OpeningFunction gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to nipidGui_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help nipidGui

% Last Modified by GUIDE v2.5 05-Aug-2005 18:26:37

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @nipidGui_OpeningFcn, ...
                   'gui_OutputFcn',  @nipidGui_OutputFcn, ...
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


% --- Executes just before nipidGui is made visible.
function nipidGui_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to nipidGui (see VARARGIN)

% Choose default command line output for nipidGui
handles.output = tf(0);

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes nipidGui wait for user response (see UIRESUME)
uiwait(handles.nipidGui);


% --- Outputs from this function are returned to the command line.
function varargout = nipidGui_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
if ~isempty(handles)
    varargout{1} = handles.output;
    delete(handles.nipidGui);
else
    varargout{1} = tf(0);
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



% --- Executes during object creation, after setting all properties.
function edit_Ts_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_Ts (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all Creat
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end



% --- Executes during object creation, after setting all properties.
function edit_wc_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_wc (see GCBO)
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
formula = get(hObject, 'Value');
switch formula
    case {1, 3, 4, 5} % CRONE, Matsuda, high and low-frequency CFE
        set(handles.edit_wl, 'Enable', 'on');
        set(handles.edit_wh, 'Enable', 'on');
        set(handles.edit_Ts, 'Enable', 'off');
        set(handles.popupmenu2, 'Enable', 'off');
        set(handles.text_warn, 'Visible', 'off');
    case 2 % Carlson
        set(handles.edit_wl, 'Enable', 'on');
        set(handles.edit_wh, 'Enable', 'on');
        set(handles.edit_Ts, 'Enable', 'off');
        set(handles.popupmenu2, 'Enable', 'off');
        set(handles.text_warn, 'Visible', 'on');
    case {6, 7, 8, 9, 10, 11} % backwards finite differences, Tustin, Simpson, delta
        set(handles.edit_wl, 'Enable', 'off');
        set(handles.edit_wh, 'Enable', 'off');
        set(handles.edit_Ts, 'Enable', 'on');
        set(handles.popupmenu2, 'String', {'MacLaurin series expansion',...
                'Continued fraction expansion',...
                'Inverted MacLaurin series expansion',...
                'Inverted continued fraction expansion'});
        set(handles.popupmenu2, 'Enable', 'on');
        set(handles.text_warn, 'Visible', 'off');
    case {12, 13} % impulse response, step response
        set(handles.edit_wl, 'Enable', 'off');
        set(handles.edit_wh, 'Enable', 'off');
        set(handles.edit_Ts, 'Enable', 'on');
        set(handles.popupmenu2, 'String', {'Time series',...
                'Continued fraction expansion',...
                'Inverted time series',...
                'Inverted continued fraction expansion'});
        set(handles.popupmenu2, 'Enable', 'on');
        set(handles.text_warn, 'Visible', 'off');
end


% --- Executes on button press in pushbutton_OK.
function pushbutton_OK_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_OK (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
kp = str2double(get(handles.edit_P, 'String'));
if isnan(kp)
    errordlg('Provide a valid real number for parameter P.', 'Error with kp', 'modal')
    return
end
ki = str2double(get(handles.edit_I, 'String'));
if isnan(ki)
    errordlg('Provide a valid real number for parameter I.', 'Error with ki', 'modal')
    return
end
kd = str2double(get(handles.edit_D, 'String'));
if isnan(kd)
    errordlg('Provide a valid real number for parameter D.', 'Error with kd', 'modal')
    return
end
vi = str2double(get(handles.edit_I_order, 'String'));
if isnan(vi)
    errordlg('Provide a valid real number for the order of the integral part.', 'Error with vi', 'modal')
    return
end
vd = str2double(get(handles.edit_D_order, 'String'));
if isnan(vd)
    errordlg('Provide a valid real number for the order of the derivative part.', 'Error with vd', 'modal')
    return
end
n = str2double(get(handles.edit_n, 'String'));
if isnan(n) | n<0 | ~isinteger(n)
    errordlg('Specify the number of zeros and poles with a valid positive integer number.', 'Error with n', 'modal')
    return
end
if (get(handles.checkbox_decomp, 'Value') == get(handles.checkbox_decomp, 'Max'))
    decomp = 'all';
else
    decomp = 'frac';
end
formula = get(handles.popupmenu1, 'Value');
if formula <= 5 % CRONE, Matsuda, Carlson, low and high-frequency CFE methods
    wl = str2double(get(handles.edit_wl, 'String'));
    if isnan(wl) | wl<=0
        errordlg('Provide a valid positive real number for the lower limit of the frequency interest range.', 'Error with wl', 'modal')
        return
    end
    wh = str2double(get(handles.edit_wh, 'String'));
    if isnan(wh) | wh<=0
        errordlg('Provide a valid positive real number for the upper limit of the frequency interest range.', 'Error with wh', 'modal')
        return
    end
    if wh <= wl
        errordlg('The upper limit of the frequency interest range should be greater than the lower.', 'Error with wl and wh', 'modal')
        return
    end
else % all discrete cases
    Ts = str2double(get(handles.edit_Ts, 'String'));
    if isnan(Ts) | Ts<=0
        errordlg('Provide a valid positive real number for the sampling time.', 'Error with Ts', 'modal')
        return
    end
    expansion = get(handles.popupmenu2, 'Value'); % numerical value...
    list = {'mcltime', 'cfe', 'mcltimeINV', 'cfeINV'};
    expansion = list{expansion}; % ... now converted into the suitable string
end
switch formula
    case 1 % CRONE
        handles.output = nipid(kp, kd, vd, ki, vi, [wl, wh], n, 'crone', [], decomp);
    case 2 % Carlson
        if isinteger(1/vd) & isinteger(vi/vd) & vd~=0 & kd~=0 & ki~=0
            s = tf('s');
            handles.output = kp +...
                newton(1, vd, [wl, wh], n, (kd^(1/vd) * s^(1+vi/vd) + ki^(1/vd)) / s^(vi/vd));
        elseif isinteger(1/vi) & isinteger(vd/vi) & vi~=0 & kd~=0 & ki~=0
            s = tf('s');
            handles.output = kp +...
                newton(1, vi, [wl, wh], n, (kd^(1/vi) * s^(1+vd/vi) + ki^(1/vi)) / s);
        else
            handles.output = nipid(kp, kd, vd, ki, vi, [wl, wh], n, 'carlson', [], decomp);
        end
    case 3 % Matsuda
        handles.output = nipid(kp, kd, vd, ki, vi, [wl, wh], n, 'matsuda', [], decomp);
    case 4 % high-frequency CFE
        handles.output = nipid(kp, kd, vd, ki, vi, [wl, wh], n, 'cfehigh', [], decomp);
    case 5 % low-frequency CFE
        handles.output = nipid(kp, kd, vd, ki, vi, [wl, wh], n, 'cfelow', [], decomp);
    case 6 % 1st backwards finite difference
        handles.output = nipid(kp, kd, vd, ki, vi, Ts, n, '1ofd', expansion, decomp);
    case 7 % 2nd backwards finite difference
        handles.output = nipid(kp, kd, vd, ki, vi, Ts, n, '2ofd', expansion, decomp);
    case 8 % 3rd backwards finite difference
        handles.output = nipid(kp, kd, vd, ki, vi, Ts, n, '3ofd', expansion, decomp);
    case 9 % Tustin
        handles.output = nipid(kp, kd, vd, ki, vi, Ts, n, 'Tustin', expansion, decomp);
    case 10 % Simpson
        handles.output = nipid(kp, kd, vd, ki, vi, Ts, n, 'Simpson', expansion, decomp);
    case 11 % delta
        handles.output = nipid(kp, kd, vd, ki, vi, Ts, n, 'delta', expansion, decomp);
    case 12 % impulse
        handles.output = nipid(kp, kd, vd, ki, vi, Ts, n, 'impulse', expansion, decomp);
    case 13 % step
        handles.output = nipid(kp, kd, vd, ki, vi, Ts, n, 'step', expansion, decomp);
end
guidata(hObject, handles);
uiresume

% --- Executes during object creation, after setting all properties.
function popupmenu2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end


% --- Executes on button press in pushbutton_Cancel.
function pushbutton_Cancel_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_Cancel (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
uiresume % this handles the closing of the function


% --- Executes during object creation, after setting all properties.
function edit_P_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_P (see GCBO)
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
function edit_I_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_I (see GCBO)
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



% --- Executes during object creation, after setting all properties.
function edit_I_order_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_I_order (see GCBO)
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
function edit_D_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_D (see GCBO)
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
function edit_D_order_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_D_order (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc
    set(hObject,'BackgroundColor','white');
else
    set(hObject,'BackgroundColor',get(0,'defaultUicontrolBackgroundColor'));
end